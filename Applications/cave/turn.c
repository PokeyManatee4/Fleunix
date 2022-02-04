
    /* TURN.C  no mods for V 1.43 
     *
     * Modified all calls of rand() to irand() for Eco-C88 (BW)
     */

#include "advent.h"

/*
        Routine to take 1 turn
*/
void turn(void)
{
	auto short i;

	/* if closing, then he can't leave except via the main office. */
	if (game.newloc < 9 && game.newloc != 0 && closing) {
		rspeak(130);
		game.newloc = game.loc;
		if (!panic)
			clock2 = 15;
		panic = 1;
	}

	/* see if a dwarf has seen him and has come from where he wants to go. */
	if (game.newloc != game.loc && !forced(game.loc) && game.cond[game.loc] & NOPIRAT == 0) {
		for (i = 1; i < (DWARFMAX - 1); ++i)
			if (odloc[i] == game.newloc && dseen[i]) {
				game.newloc = game.loc;
				rspeak(2);
				break;
			}
	}
	dwarves();

	/* on to the regular move. */
	if (game.loc != game.newloc) {
		++game.turns;
		game.loc = game.newloc;

		/* check for death */
		if (game.loc == 0) {
			death();
			return;
		}

		/* check for forced move */
		if (forced(game.loc)) {
			describe();
			domove();
			return;
		}

		/* check for wandering in dark */
		if (wzdark && dark() && pct(35)) {
			rspeak(23);
			game.oldloc2 = game.loc;
			death();
			return;
		}

		/* describe his situation */
		describe();
		if (!dark()) {
			/* FIXME?? doesn't this mean 65536 visits breaks ?? */
			++game.visited[game.loc];
			descitem();
		}
	}
	if (closed) {
		if (prop[OYSTER] < 0 && toting(OYSTER))
			pspeak(OYSTER, 1);
		for (i = 1; i <= MAXOBJ; ++i) {
			if (toting(i) && prop[i] < 0)
				prop[i] = -1 - prop[i];
		}
	}
	wzdark = dark();
	if (knfloc > 0 && knfloc != game.loc)
		knfloc = 0;

	/* run the timer routine */
	if (stimer())
		return;

	/* ask what he wants to do */
	/* debug */
#ifdef DEBUG
	if (game.dbgflg)
		printf("Your current location is %d\n", game.loc);
#endif				/*  */
	while (!english());

	/* act on his instructions */
	if (motion)
		domove();

	else {
		if (object)
			doobj();

		else
			itverb();
	}
	return;
}


/*
        Routine to describe current location
*/
void describe(void)
{
	if (toting(BEAR))
		rspeak(141);
	if (dark())
		rspeak(16);

	else {
		if (game.visited[game.loc] && brief_sw)
			descsh(game.loc);

		else
			desclg(game.loc);
	}
	if (game.loc == 33 && pct(25) && !closing)
		rspeak(8);
	return;
}


/*
        Routine to describe visible items
*/
void descitem(void)
{
	auto short i, state;
	for (i = 1; i < MAXOBJ; ++i) {
		if (at(i)) {
			if (i == STEPS && toting(NUGGET))
				continue;
			if (prop[i] < 0) {
				if (closed)
					continue;

				else {
					prop[i] = 0;
					if (i == RUG || i == CHAIN)
						++prop[i];
					--tally;
				}
			}
			if (i == STEPS && game.loc == fixed[STEPS])
				state = 1;

			else
				state = prop[i];
			pspeak(i, state);
		}
	}
	if (tally == tally2 && tally != 0 && limit > 35)
		limit = 35;
	return;
}


/*
        Routine to handle motion requests
*/
void domove(void)
{
	gettrav(game.loc);
	switch (motion) {
	case NULLX:
		break;
	case BACK:
		goback();
		break;
	case LOOK:
		if (detail++ < 3)
			rspeak(15);
		wzdark = 0;
		game.visited[game.loc] = 0;
		game.newloc = game.loc;
		game.loc = 0;
		break;
	case CAVE:
		if (game.loc < 8)
			rspeak(57);

		else
			rspeak(58);
		break;
	default:
		game.oldloc2 = game.oldloc;
		game.oldloc = game.loc;
		dotrav();
		game.loc = 0;	/* Modified BW 09/28/85   */
	}
	return;
}


/*
        Routine to handle request to return
        from whence we came!
*/
void goback(void)
{
	auto short kk, k2, want, temp;
	auto TRAV *pSavTrav;
	auto short sSavCnt;
	if (forced(game.oldloc))
		want = game.oldloc2;

	else
		want = game.oldloc;
	game.oldloc2 = game.oldloc;
	game.oldloc = game.loc;
	k2 = 0;
	if (want == game.loc) {
		rspeak(91);
		return;
	}
	pSavTrav = pTravel;
	sSavCnt = sTravCnt;
	for (kk = 0; kk < sTravCnt; ++kk) {
		if (!pTravel[kk].tcond && pTravel[kk].tdest == want) {
			motion = pTravel[kk].tverb;
			dotrav();
			return;
		}
		if (!pTravel[kk].tcond) {
			k2 = kk;
			temp = pTravel[kk].tdest;
			gettrav(temp);
			if (forced(temp) && pTravel[0].tdest == want)
				k2 = temp;
			pTravel = pSavTrav;
			sTravCnt = sSavCnt;
		}
	}
	if (k2) {
		motion = pTravel[k2].tverb;
		dotrav();
	}

	else
		rspeak(140);
	return;
}


/*
        Routine to figure out a new location
        given current location and a motion.
*/
void dotrav(void)
{
	auto short mvflag, hitflag, kk;
	auto short rdest, rverb, rcond, robject;
	auto short pctt;
	game.newloc = game.loc;
	mvflag = hitflag = 0;
	pctt = rand() % 100;
	for (kk = 0; kk < sTravCnt && !mvflag; ++kk) {
		rdest = pTravel[kk].tdest;
		rverb = pTravel[kk].tverb;
		rcond = pTravel[kk].tcond;
		robject = rcond % 100;
		if (rverb != 1 && rverb != motion && !hitflag)
			continue;
		++hitflag;
		switch (rcond / 100) {
		case 0:
			if (rcond == 0 || pctt < rcond)
				++mvflag;

			/* debug */
#ifdef DEBUG
			if (rcond && game.dbgflg)
				printf("\% move %d %d\n", pctt, mvflag);

#endif				/*  */
			break;
		case 1:
			if (robject == 0)
				++mvflag;

			else {
				if (toting(robject))
					++mvflag;
			}
			break;
		case 2:
			if (toting(robject) || at(robject))
				++mvflag;
			break;
		case 3:
		case 4:
		case 5:
		case 7:
			if (prop[robject] != (rcond / 100) - 3)
				++mvflag;
			break;
		default:
			bug(37);
		}
	}
	if (!mvflag)
		badmove();

	else {
		if (rdest > 500)
			rspeak(rdest - 500);

		else {
			if (rdest > 300)
				spcmove(rdest);

			else
				game.newloc = rdest;
		}
	}
	return;
}


/*
        The player tried a poor move option.
*/
void badmove(void)
{
	auto short msg;
	msg = 12;
	if (motion >= 43 && motion <= 50)
		msg = 9;
	if (motion == 29 || motion == 30)
		msg = 9;
	if (motion == 7 || motion == 36 || motion == 37)
		msg = 10;
	if (motion == 11 || motion == 19)
		msg = 11;
	if (verb == FIND || verb == INVENTORY)
		msg = 59;
	if (motion == 62 || motion == 65)
		msg = 42;
	if (motion == 17)
		msg = 80;
	rspeak(msg);
	return;
}


/*
        Routine to handle very special movement.
*/
void spcmove(short rdest)
{
	switch (rdest - 300) {
	case 1:		/* plover movement via alcove */
		if (!holding || (holding == 1 && toting(EMERALD)))
			game.newloc = (99 + 100) - game.loc;

		else
			rspeak(117);
		break;
	case 2:		/* trying to remove plover, bad route */
		drop(EMERALD, game.loc);
		break;
	case 3:		/* troll bridge */
		if (prop[TROLL] == 1) {
			pspeak(TROLL, 1);
			prop[TROLL] = 0;
			move(TROLL2, 0);
			move((TROLL2 + MAXOBJ), 0);
			move(TROLL, 117);
			move((TROLL + MAXOBJ), 122);
			juggle(CHASM);
			game.newloc = game.loc;
		}

		else {
			game.newloc = (game.loc == 117 ? 122 : 117);
			if (prop[TROLL] == 0)
				++prop[TROLL];
			if (!toting(BEAR))
				return;
			rspeak(162);
			prop[CHASM] = 1;
			prop[TROLL] = 2;
			drop(BEAR, game.newloc);
			fixed[BEAR] = -1;
			prop[BEAR] = 3;
			if (prop[SPICES] < 0)
				++tally2;
			game.oldloc2 = game.newloc;
			death();
		}
		break;
	default:
		bug(38);
	}
	return;
}


/*
        Routine to handle player's demise via
        waking up the dwarves...
*/
void dwarfend(void)
{
	death();
	normend();		/* no return from here */
}

/*
        normal end of game
*/
void normend(void)
{
	score();
	exit(1);
}

/*
        scoring
*/
void score(void)
{
	auto short t, i, k, s;
	s = t = 0;
	for (i = 50; i <= MAXTRS; ++i) {
		if (i == CHEST)
			k = 14;

		else
			k = i > CHEST ? 16 : 12;
		if (prop[i] >= 0)
			t += 2;
		if (place[i] == 3 && prop[i] == 0)
			t += k - 2;
	}
	writes("Treasures           ");
	writei(s = t);
	t = (MAXDIE - numdie) * 10;
	if (t) {
		writes("\nSurvival            ");
		writei(t);
	}
	s += t;
	if (!gaveup)
		s += 4;
	t = dflag ? 25 : 0;
	if (t) {
		writes("\nGetting well in:    ");
		writei(t);
	}
	s += t;
	t = closing ? 25 : 0;
	if (t) {
		writes("\nMasters section:    ");
		writei(t);
	}
	s += t;
	if (closed) {
		if (bonus == 0)
			t = 10;

		else {
			if (bonus == 135)
				t = 25;

			else {
				if (bonus == 134)
					t = 30;

				else {
					if (bonus == 133)
						t = 45;
				}
			}
		}
		writes("\nBonus               ");
		writei(t);
		s += t;
	}
	if (place[MAGAZINE] == 108)
		s += 1;
	s += 2;
	writes("\nScore:              ");
	writei(s);
	nl();
	return;
}


/*
        Routine to handle the passing on of one
        of the player's incarnations...
*/
void death(void)
{
	auto short yea, i, j;
	if (!closing) {
		yea = yes(81 + numdie * 2, 82 + numdie * 2, 54);
		if (++numdie >= MAXDIE || !yea)
			normend();
		place[WATER] = 0;
		place[OIL] = 0;
		if (toting(LAMP))
			prop[LAMP] = 0;
		for (j = 1; j < 101; ++j) {
			i = 101 - j;
			if (toting(i))
				drop(i, i == LAMP ? 1 : game.oldloc2);
		}
		game.newloc = 3;
		game.oldloc = game.loc;
		return;
	}

	/* closing -- no resurrection... */
	rspeak(131);
	++numdie;
	normend();		/* no return from here */
}


/*
        Routine to process an object.
*/
void doobj(void)
{

	/* is object here?  if so, transitive */
	if (fixed[object] == game.loc || here(object))
		trobj();

	/* did he give grate as destination? */
	else {
		if (object == GRATE) {
			if (game.loc == 1 || game.loc == 4 || game.loc == 7) {
				motion = DEPRESSION;
				domove();
			}

			else {
				if (game.loc > 9 && game.loc < 15) {
					motion = ENTRANCE;
					domove();
				}
			}
		}

		/* is it a dwarf he is after? */
		else {
			if (dcheck() && dflag >= 2) {
				object = DWARF;
				trobj();
			}

			/* is he trying to get/use a liquid? */
			else {
				if ((liq() == object && here(BOTTLE)) || liqloc(game.loc) == object)
					trobj();

				else {
					if (object == PLANT && at(PLANT2) && prop[PLANT2] == 0) {
						object = PLANT2;
						trobj();
					}

					/* is he trying to grab a knife? */
					else {
						if (object == KNIFE && knfloc == game.loc) {
							rspeak(116);
							knfloc = -1;
						}

						/* is he trying to get at dynamite? */
						else {
							if (object == ROD && here(ROD2)) {
								object = ROD2;
								trobj();
							}

							else {
								writes("I see no ");
								writes(probj(object));
								writes(" here.\n");
							}
						}
					}
				}
			}
		}
	}
	return;
}

/*
        Routine to process an object being
        referred to.
*/
void trobj(void)
{
	if (verb)
		trverb();

	else {
		writes("What do you want to do with the ");
		writes(probj(object));
		writes("?\n");
	}
	return;
}

/*
        Routine to print word corresponding to object
*/
char *probj(short object)
{
	auto short wtype, wval;
	analyze(word1, &wtype, &wval);
	return ((wtype == 1) ? word1 : word2);
}

/*
        dwarf stuff.
*/
void dwarves(void)
{
	auto short i, j, k, try, attack, stick, dtotal;

	/* see if dwarves allowed here */
	if (game.newloc == 0 || forced(game.newloc) || game.cond[game.newloc] & NOPIRAT)
		return;

	/* see if dwarves are active. */
	if (!dflag) {
		if (game.newloc > 15)
			++dflag;
		return;
	}

	/* if first close encounter (of 3rd kind) kill 0, 1 or 2 */
	if (dflag == 1) {
		if (game.newloc < 15 || pct(95))
			return;
		++dflag;
		for (i = 1; i < 3; ++i) {
			if (pct(50))
				dloc[rand() % 5 + 1] = 0;
		}
		for (i = 1; i < (DWARFMAX - 1); ++i) {
			if (dloc[i] == game.newloc)
				dloc[i] = daltloc;
			odloc[i] = dloc[i];
		}
		rspeak(3);
		drop(AXE, game.newloc);
		return;
	}
	dtotal = attack = stick = 0;
	for (i = 1; i < DWARFMAX; ++i) {
		if (dloc[i] == 0)
			continue;

		/* move a dwarf at random.  we don't have a matrix around to do it as
		 * in the original version... */
		for (try = 1; try < 20; ++try) {
			j = rand() % 106 + 15;	/* allowed area */
			if (j != odloc[i] && j != dloc[i] && !(i == (DWARFMAX - 1) && game.cond[j] & NOPIRAT == 1))
				break;
		}
		if (j == 0)
			j = odloc[i];
		odloc[i] = dloc[i];
		dloc[i] = j;
		if ((dseen[i] && game.newloc >= 15) || dloc[i] == game.newloc || odloc[i] == game.newloc)
			dseen[i] = 1;

		else
			dseen[i] = 0;
		if (!dseen[i])
			continue;
		dloc[i] = game.newloc;
		if (i == 6)
			dopirate();

		else {
			++dtotal;
			if (odloc[i] == dloc[i]) {
				++attack;
				if (knfloc >= 0)
					knfloc = game.newloc;
				if (rand() % 1000 < 30 * (dflag - 2))
					++stick;
			}
		}
	}
	if (dtotal == 0)
		return;
	if (dtotal > 1) {
		writes("There are ");
		writei(dtotal);
		writes(" threatening little dwarves in the room with you!\n");
	} else
		rspeak(4);
	if (attack == 0)
		return;
	if (dflag == 2)
		++dflag;
	if (attack > 1) {
		writei(attack);
		writes(" of them throw knives at you!!\n");
		k = 6;
	}

	else {
		rspeak(5);
		k = 52;
	}
	if (stick <= 1) {
		rspeak(stick + k);
		if (stick == 0)
			return;
	}

	else {
		writei(stick);
		writes(" of them get you !!!\n");
	}
	game.oldloc2 = game.newloc;
	death();
	return;
}

/*
        pirate stuff
*/
void dopirate(void)
{
	auto short j, k;
	if (game.newloc == chloc || prop[CHEST] >= 0)
		return;
	k = 0;
	for (j = 50; j <= MAXTRS; ++j)
		if (j != PYRAMID || (game.newloc != place[PYRAMID] && game.newloc != place[EMERALD])) {
			if (toting(j))
				goto stealit;
			if (here(j))
				++k;
		}
	if (tally == tally2 + 1 && k == 0 && place[CHEST] == 0 && here(LAMP) && prop[LAMP] == 1) {
		rspeak(186);
		move(CHEST, chloc);
		move(MESSAGE, chloc2);
		dloc[6] = chloc;
		odloc[6] = chloc;
		dseen[6] = 0;
		return;
	}
	if (odloc[6] != dloc[6] && pct(20)) {
		rspeak(127);
		return;
	}
	return;
      stealit:rspeak(128);
	if (place[MESSAGE] == 0)
		move(CHEST, chloc);
	move(MESSAGE, chloc2);
	for (j = 50; j <= MAXTRS; ++j) {
		if (j == PYRAMID && (game.newloc == place[PYRAMID] || game.newloc == place[EMERALD]))
			continue;
		if (at(j) && fixed[j] == 0)
			carry(j, game.newloc);
		if (toting(j))
			drop(j, chloc);
	}
	dloc[6] = chloc;
	odloc[6] = chloc;
	dseen[6] = 0;
	return;
}

/*
        special time limit stuff...
*/
uint8_t stimer(void)
{
	register short i;
	game.foobar = game.foobar > 0 ? -game.foobar : 0;
	if (tally == 0 && game.loc >= 15 && game.loc != 33)
		--clock1;
	if (clock1 == 0) {

		/* start closing the cave */
		prop[GRATE] = 0;
		prop[FISSURE] = 0;
		for (i = 1; i < DWARFMAX; ++i)
			dseen[i] = 0;
		move(TROLL, 0);
		move((TROLL + MAXOBJ), 0);
		move(TROLL2, 117);
		move((TROLL2 + MAXOBJ), 122);
		juggle(CHASM);
		if (prop[BEAR] != 3)
			dstroy(BEAR);
		prop[CHAIN] = 0;
		fixed[CHAIN] = 0;
		prop[AXE] = 0;
		fixed[AXE] = 0;
		rspeak(129);
		clock1 = -1;
		closing = 1;
		return (FALSE);
	}
	if (clock1 < 0)
		--clock2;
	if (clock2 == 0) {

		/* set up storage room... and close the cave... */
		prop[BOTTLE] = put(BOTTLE, 115, 1);
		prop[PLANT] = put(PLANT, 115, 0);
		prop[OYSTER] = put(OYSTER, 115, 0);
		prop[LAMP] = put(LAMP, 115, 0);
		prop[ROD] = put(ROD, 115, 0);
		prop[DWARF] = put(DWARF, 115, 0);
		game.loc = 115;
		game.oldloc = 115;
		game.newloc = 115;
		put(GRATE, 116, 0);
		prop[SNAKE] = put(SNAKE, 116, 1);
		prop[BIRD] = put(BIRD, 116, 1);
		prop[CAGE] = put(CAGE, 116, 0);
		prop[ROD2] = put(ROD2, 116, 0);
		prop[PILLOW] = put(PILLOW, 116, 0);
		prop[MIRROR] = put(MIRROR, 115, 0);
		fixed[MIRROR] = 116;
		for (i = 1; i <= MAXOBJ; ++i)
			if (toting(i))
				dstroy(i);
		rspeak(132);
		closed = 1;
		return (TRUE);
	}
	if (prop[LAMP] == 1)
		--limit;
	if (limit <= 30 && here(BATTERIES) && prop[BATTERIES] == 0 && here(LAMP)) {
		rspeak(188);
		prop[BATTERIES] = 1;
		if (toting(BATTERIES))
			drop(BATTERIES, game.loc);
		limit += 2500;
		lmwarn = 0;
		return (FALSE);
	}
	if (limit == 0) {
		--limit;
		prop[LAMP] = 0;
		if (here(LAMP))
			rspeak(184);
		return (FALSE);
	}
	if (limit < 0 && game.loc <= 8) {
		rspeak(185);
		gaveup = 1;
		normend();
	}
	if (limit <= 30) {
		if (lmwarn || !here(LAMP))
			return (FALSE);
		lmwarn = 1;
		i = 187;
		if (place[BATTERIES] == 0)
			i = 183;
		if (prop[BATTERIES] == 1)
			i = 189;
		rspeak(i);
	}
	return (FALSE);
}

#define NUM_OBJ 66
#define WORDSIZE 3
#define GAME_MAGIC 416
#include <stdint.h>

struct location {
  const uint8_t *text;
  uint8_t exit[6];
};

const uint8_t toomuch[] = { "I am carrying too much. " };
const uint8_t dead[] = { "I am dead.\n" };
const uint8_t stored_msg[] = { "I have stored " };
const uint8_t stored_msg2[] = { " treasures. On a scale of 0 to 100, that rates " };
const uint8_t dotnewline[] = { ".\n" };
const uint8_t newline[] = { "\n" };
const uint8_t carrying[] = { "I am carrying:\n" };
const uint8_t dashstr[] = { " - " };
const uint8_t nothing[] = { "nothing" };
const uint8_t lightout[] = { "My light has run out." };
const uint8_t lightoutin[] = { "My light runs out in " };
const uint8_t turns[] = { "turns" };
const uint8_t turn[] = { "turn" };
const uint8_t whattodo[] = { "\nTell me what to do ? " };
const uint8_t prompt[] = { "\n> " };
const uint8_t dontknow[] = { "You use word(s) I don't know! " };
const uint8_t givedirn[] = { "Give me a direction too. " };
const uint8_t darkdanger[] = { "Dangerous to move in the dark! " };
const uint8_t brokeneck[] = { "I fell down and broke my neck. " };
const uint8_t cantgo[] = { "I can't go in that direction. " };
const uint8_t dontunderstand[] = { "I don't understand your command. " };
const uint8_t notyet[] = { "I can't do that yet. " };
const uint8_t beyondpower[] = { "It is beyond my power to do that. " };
const uint8_t okmsg[] = { "O.K. " };
const uint8_t whatstr[] = { "What ? " };
const uint8_t itsdark[] = { "I can't see. It is too dark!" };
const uint8_t youare[] = { "I am in a " };
const uint8_t nonestr[] = { "none" };
const uint8_t obexit[] = { "\nObvious exits: " };
const uint8_t canalsosee[] = { "I can also see: " };
const uint8_t playagain[] = { "Do you want to play again Y/N: " };
const uint8_t invcond[] = { "INVCOND" };
const uint8_t *exitmsgptr[] = {
  (uint8_t *)"North",
  (uint8_t *)"South",
  (uint8_t *)"East",
  (uint8_t *)"West",
  (uint8_t *)"Up",
  (uint8_t *)"Down"
};



/*
 * 
 *	Game database follows below. Although linked into the same asm
 *	file to make life easier this is just "mere aggregation" for
 *	convenience, due to limits in the tool chain and the game licence
 *	not the GPL applies to the game database.
 */
const uint8_t startlamp = 125;
const uint8_t lightfill = 125;
const uint8_t startcarried = 0;
const uint8_t maxcar = 6;
const uint8_t treasure = 3;
const uint8_t treasures = 13;
const uint8_t lastloc = 33;
const uint8_t startloc = 11;


const struct location locdata[] = {
		{ 	"",
 { 0, 7, 10, 1, 0, 24 } }, 
		{ 	"\x64\x69\x73\x6D\x61\x6C\x20\x73\x77\x61\x6D\x70",
 { 23, 0, 29, 25, 0, 0 } }, 
		{ 	"\x74\x6F\x70\x20\x6F\x66\x20\x61\x20\x74\x61\x6C\x6C\x20\x63\x79\x70\x72\x65\x73\x73\x20\x74\x72\x65\x65",
 { 0, 0, 0, 0, 0, 1 } }, 
		{ 	"\x64\x61\x6D\x70\x20\x68\x6F\x6C\x6C\x6F\x77\x20\x73\x74\x75\x6D\x70\x20\x69\x6E\x20\x74\x68\x65\x20\x73\x77\x61\x6D\x70",
 { 0, 0, 0, 0, 1, 4 } }, 
		{ 	"\x72\x6F\x6F\x74\x20\x63\x68\x61\x6D\x62\x65\x72\x20\x75\x6E\x64\x65\x72\x20\x74\x68\x65\x20\x73\x74\x75\x6D\x70",
 { 0, 0, 0, 0, 3, 0 } }, 
		{ 	"\x73\x65\x6D\x69\x2D\x64\x61\x72\x6B\x20\x68\x6F\x6C\x65\x20\x62\x79\x20\x74\x68\x65\x20\x72\x6F\x6F\x74\x20\x63\x68\x61\x6D\x62\x65\x72",
 { 0, 0, 0, 0, 4, 0 } }, 
		{ 	"\x6C\x6F\x6E\x67\x20\x64\x6F\x77\x6E\x20\x73\x6C\x6F\x70\x69\x6E\x67\x20\x68\x61\x6C\x6C",
 { 0, 0, 0, 0, 5, 7 } }, 
		{ 	"\x6C\x61\x72\x67\x65\x20\x63\x61\x76\x65\x72\x6E",
 { 31, 9, 0, 27, 6, 12 } }, 
		{ 	"\x6C\x61\x72\x67\x65\x20\x38\x20\x73\x69\x64\x65\x64\x20\x72\x6F\x6F\x6D",
 { 0, 31, 0, 0, 0, 0 } }, 
		{ 	"\x72\x6F\x79\x61\x6C\x20\x61\x6E\x74\x65\x72\x6F\x6F\x6D",
 { 7, 0, 0, 0, 20, 0 } }, 
		{ 	"\x2A\x49\x27\x6D\x20\x6F\x6E\x20\x74\x68\x65\x20\x73\x68\x6F\x72\x65\x20\x6F\x66\x20\x61\x20\x6C\x61\x6B\x65",
 { 26, 29, 0, 23, 0, 0 } }, 
		{ 	"\x66\x6F\x72\x65\x73\x74",
 { 11, 11, 23, 11, 0, 0 } }, 
		{ 	"\x6D\x61\x7A\x65\x20\x6F\x66\x20\x70\x69\x74\x73",
 { 13, 15, 15, 0, 0, 13 } }, 
		{ 	"\x6D\x61\x7A\x65\x20\x6F\x66\x20\x70\x69\x74\x73",
 { 0, 0, 0, 14, 12, 0 } }, 
		{ 	"\x6D\x61\x7A\x65\x20\x6F\x66\x20\x70\x69\x74\x73",
 { 17, 12, 13, 16, 16, 17 } }, 
		{ 	"\x6D\x61\x7A\x65\x20\x6F\x66\x20\x70\x69\x74\x73",
 { 12, 0, 13, 12, 13, 0 } }, 
		{ 	"\x6D\x61\x7A\x65\x20\x6F\x66\x20\x70\x69\x74\x73",
 { 0, 17, 0, 0, 14, 17 } }, 
		{ 	"\x6D\x61\x7A\x65\x20\x6F\x66\x20\x70\x69\x74\x73",
 { 17, 12, 12, 15, 14, 18 } }, 
		{ 	"\x2A\x49\x27\x6D\x20\x61\x74\x20\x74\x68\x65\x20\x62\x6F\x74\x74\x6F\x6D\x20\x6F\x66\x20\x61\x20\x76\x65\x72\x79\x20\x64\x65\x65\x70\x20\x63\x68\x61\x73\x6D\x2E\x20\x48\x69\x67\x68\x20\x61\x62\x6F\x76\x65\x20\x6D\x65\x20\x69\x73\x0A\x61\x20\x70\x61\x69\x72\x20\x6F\x66\x20\x6C\x65\x64\x67\x65\x73\x2E\x20\x4F\x6E\x65\x20\x68\x61\x73\x20\x61\x20\x62\x72\x69\x63\x6B\x65\x64\x20\x75\x70\x20\x77\x69\x6E\x64\x6F\x77\x20\x61\x63\x72\x6F\x73\x73\x20\x69\x74\x73\x20\x66\x61\x63\x65\x0A\x74\x68\x65\x20\x6F\x74\x68\x65\x72\x20\x66\x61\x63\x65\x73\x20\x61\x20\x54\x68\x72\x6F\x6E\x65\x2D\x72\x6F\x6F\x6D",
 { 0, 0, 0, 0, 17, 0 } }, 
		{ 	"\x2A\x49\x27\x6D\x20\x6F\x6E\x20\x61\x20\x6E\x61\x72\x72\x6F\x77\x20\x6C\x65\x64\x67\x65\x20\x62\x79\x20\x61\x20\x63\x68\x61\x73\x6D\x2E\x20\x41\x63\x72\x6F\x73\x73\x20\x74\x68\x65\x20\x63\x68\x61\x73\x6D\x20\x69\x73\x0A\x74\x68\x65\x20\x54\x68\x72\x6F\x6E\x65\x2D\x72\x6F\x6F\x6D",
 { 0, 0, 0, 20, 0, 0 } }, 
		{ 	"\x72\x6F\x79\x61\x6C\x20\x63\x68\x61\x6D\x62\x65\x72",
 { 0, 0, 0, 0, 0, 9 } }, 
		{ 	"\x2A\x49\x27\x6D\x20\x6F\x6E\x20\x61\x20\x6E\x61\x72\x72\x6F\x77\x20\x6C\x65\x64\x67\x65\x20\x62\x79\x20\x61\x20\x54\x68\x72\x6F\x6E\x65\x2D\x72\x6F\x6F\x6D\x0A\x41\x63\x72\x6F\x73\x73\x20\x74\x68\x65\x20\x63\x68\x61\x73\x6D\x20\x69\x73\x20\x61\x6E\x6F\x74\x68\x65\x72\x20\x6C\x65\x64\x67\x65",
 { 0, 0, 0, 0, 0, 0 } }, 
		{ 	"\x74\x68\x72\x6F\x6E\x65\x20\x72\x6F\x6F\x6D",
 { 0, 0, 0, 21, 0, 0 } }, 
		{ 	"\x73\x75\x6E\x6E\x79\x20\x6D\x65\x61\x64\x6F\x77",
 { 0, 1, 10, 11, 0, 0 } }, 
		{ 	"\x2A\x49\x20\x74\x68\x69\x6E\x6B\x20\x49\x27\x6D\x20\x69\x6E\x20\x72\x65\x61\x6C\x20\x74\x72\x6F\x75\x62\x6C\x65\x20\x6E\x6F\x77\x2E\x20\x54\x68\x65\x72\x65\x27\x73\x20\x61\x20\x66\x65\x6C\x6C\x6F\x77\x20\x68\x65\x72\x65\x20\x77\x69\x74\x68\x0A\x61\x20\x70\x69\x74\x63\x68\x66\x6F\x72\x6B\x20\x61\x6E\x64\x20\x70\x6F\x69\x6E\x74\x65\x64\x20\x74\x61\x69\x6C\x2E\x20\x2E\x2E\x2E\x4F\x68\x20\x48\x65\x6C\x6C\x21",
 { 0, 0, 0, 0, 0, 0 } }, 
		{ 	"\x68\x69\x64\x64\x65\x6E\x20\x67\x72\x6F\x76\x65",
 { 11, 0, 1, 0, 0, 0 } }, 
		{ 	"\x71\x75\x69\x63\x6B\x2D\x73\x61\x6E\x64\x20\x62\x6F\x67",
 { 0, 0, 0, 0, 0, 0 } }, 
		{ 	"\x4D\x65\x6D\x6F\x72\x79\x20\x63\x68\x69\x70\x20\x6F\x66\x20\x61\x20\x43\x4F\x4D\x50\x55\x54\x45\x52\x21\x0A\x49\x20\x74\x6F\x6F\x6B\x20\x61\x20\x77\x72\x6F\x6E\x67\x20\x74\x75\x72\x6E\x21",
 { 0, 0, 7, 0, 0, 0 } }, 
		{ 	"\x74\x6F\x70\x20\x6F\x66\x20\x61\x6E\x20\x6F\x61\x6B\x2E\x0A\x54\x6F\x20\x74\x68\x65\x20\x45\x61\x73\x74\x20\x49\x20\x73\x65\x65\x20\x61\x20\x6D\x65\x61\x64\x6F\x77\x2C\x20\x62\x65\x79\x6F\x6E\x64\x20\x74\x68\x61\x74\x20\x61\x20\x6C\x61\x6B\x65\x2E",
 { 0, 0, 0, 0, 0, 11 } }, 
		{ 	"\x2A\x49\x27\x6D\x20\x61\x74\x20\x74\x68\x65\x20\x65\x64\x67\x65\x20\x6F\x66\x20\x61\x20\x42\x4F\x54\x54\x4F\x4D\x4C\x45\x53\x53\x20\x68\x6F\x6C\x65",
 { 10, 0, 0, 1, 0, 0 } }, 
		{ 	"\x2A\x49\x27\x6D\x20\x6F\x6E\x20\x61\x20\x6C\x65\x64\x67\x65\x20\x6A\x75\x73\x74\x20\x62\x65\x6C\x6F\x77\x20\x74\x68\x65\x20\x72\x69\x6D\x20\x6F\x66\x20\x74\x68\x65\x20\x42\x4F\x54\x54\x4F\x4D\x4C\x45\x53\x53\x20\x68\x6F\x6C\x65\x2E\x20\x49\x0A\x64\x6F\x6E\x27\x74\x20\x74\x68\x69\x6E\x6B\x20\x49\x20\x77\x61\x6E\x74\x20\x74\x6F\x20\x67\x6F\x20\x64\x6F\x77\x6E",
 { 0, 0, 0, 0, 29, 24 } }, 
		{ 	"\x6C\x6F\x6E\x67\x20\x74\x75\x6E\x6E\x65\x6C\x2E\x20\x49\x20\x68\x65\x61\x72\x20\x62\x75\x7A\x7A\x69\x6E\x67\x20\x61\x68\x65\x61\x64",
 { 8, 7, 0, 0, 0, 0 } }, 
		{ 	"\x2A\x49\x27\x6D\x20\x69\x6E\x20\x61\x6E\x20\x65\x6E\x64\x6C\x65\x73\x73\x20\x63\x6F\x72\x72\x69\x64\x6F\x72",
 { 32, 33, 32, 32, 32, 32 } }, 
		{ 	"\x6C\x61\x72\x67\x65\x20\x6D\x69\x73\x74\x79\x20\x72\x6F\x6F\x6D\x20\x77\x69\x74\x68\x20\x73\x74\x72\x61\x6E\x67\x65\x0A\x75\x6E\x72\x65\x61\x64\x61\x62\x6C\x65\x20\x6C\x65\x74\x74\x65\x72\x73\x20\x6F\x76\x65\x72\x20\x61\x6C\x6C\x20\x74\x68\x65\x20\x65\x78\x69\x74\x73\x2E",
 { 32, 24, 11, 24, 28, 24 } }, 
};
const uint8_t objinit[] = {
	0,
	4,
	4,
	2,
	0,
	1,
	10,
	1,
	10,
	0,
	3,
	10,
	3,
	0,
	2,
	3,
	5,
	0,
	1,
	18,
	0,
	0,
	1,
	8,
	8,
	21,
	0,
	23,
	30,
	17,
	18,
	0,
	20,
	23,
	18,
	0,
	0,
	22,
	21,
	0,
	9,
	0,
	1,
	0,
	0,
	0,
	25,
	26,
	0,
	0,
	14,
	33,
	0,
	10,
	17,
	0,
	0,
	25,
	11,
	12,
	0,
	0,
	29,
	29,
	0,
	0,
};


const uint8_t *objtext[] = {
	"\x47\x6C\x6F\x77\x69\x6E\x67\x20\x2A\x46\x49\x52\x45\x53\x54\x4F\x4E\x45\x2A",
	"\x44\x61\x72\x6B\x20\x68\x6F\x6C\x65",
	"\x2A\x50\x6F\x74\x20\x6F\x66\x20\x52\x55\x42\x49\x45\x53\x2A",
	"\x53\x70\x69\x64\x65\x72\x20\x77\x65\x62\x20\x77\x69\x74\x68\x20\x77\x72\x69\x74\x69\x6E\x67\x20\x6F\x6E\x20\x69\x74",
	"\x2D\x48\x4F\x4C\x4C\x4F\x57\x2D\x20\x73\x74\x75\x6D\x70\x20\x61\x6E\x64\x20\x72\x65\x6D\x61\x69\x6E\x73\x20\x6F\x66\x20\x61\x20\x66\x65\x6C\x6C\x65\x64\x20\x74\x72\x65\x65",
	"\x43\x79\x70\x72\x65\x73\x73\x20\x74\x72\x65\x65",
	"\x57\x61\x74\x65\x72",
	"\x45\x76\x69\x6C\x20\x73\x6D\x65\x6C\x6C\x69\x6E\x67\x20\x6D\x75\x64",
	"\x2A\x47\x4F\x4C\x44\x45\x4E\x20\x46\x49\x53\x48\x2A",
	"\x4C\x69\x74\x20\x62\x72\x61\x73\x73\x20\x6C\x61\x6D\x70",
	"\x4F\x6C\x64\x20\x66\x61\x73\x68\x69\x6F\x6E\x65\x64\x20\x62\x72\x61\x73\x73\x20\x6C\x61\x6D\x70",
	"\x52\x75\x73\x74\x79\x20\x61\x78\x65\x20\x28\x4D\x61\x67\x69\x63\x20\x77\x6F\x72\x64\x20\x22\x42\x55\x4E\x59\x4F\x4E\x22\x20\x6F\x6E\x20\x69\x74\x29",
	"\x57\x61\x74\x65\x72\x20\x69\x6E\x20\x62\x6F\x74\x74\x6C\x65",
	"\x45\x6D\x70\x74\x79\x20\x62\x6F\x74\x74\x6C\x65",
	"\x52\x69\x6E\x67\x20\x6F\x66\x20\x73\x6B\x65\x6C\x65\x74\x6F\x6E\x20\x6B\x65\x79\x73",
	"\x53\x69\x67\x6E\x20\x22\x4C\x65\x61\x76\x65\x20\x2A\x54\x52\x45\x41\x53\x55\x52\x45\x53\x2A\x20\x68\x65\x72\x65\x2C\x20\x74\x68\x65\x6E\x20\x73\x61\x79\x3A\x20\x53\x43\x4F\x52\x45\x22",
	"\x4C\x6F\x63\x6B\x65\x64\x20\x64\x6F\x6F\x72",
	"\x4F\x70\x65\x6E\x20\x64\x6F\x6F\x72\x20\x77\x69\x74\x68\x20\x61\x20\x68\x61\x6C\x6C\x77\x61\x79\x20\x62\x65\x79\x6F\x6E\x64",
	"\x53\x77\x61\x6D\x70\x20\x67\x61\x73",
	"\x2A\x47\x4F\x4C\x44\x45\x4E\x20\x4E\x45\x54\x2A",
	"\x43\x68\x69\x67\x67\x65\x72\x20\x62\x69\x74\x65\x73",
	"\x49\x6E\x66\x65\x63\x74\x65\x64\x20\x63\x68\x69\x67\x67\x65\x72\x20\x62\x69\x74\x65\x73",
	"\x50\x61\x74\x63\x68\x65\x73\x20\x6F\x66\x20\x22\x4F\x49\x4C\x59\x22\x20\x73\x6C\x69\x6D\x65",
	"\x2A\x52\x4F\x59\x41\x4C\x20\x48\x4F\x4E\x45\x59\x2A",
	"\x4C\x61\x72\x67\x65\x20\x61\x66\x72\x69\x63\x61\x6E\x20\x62\x65\x65\x73",
	"\x56\x65\x72\x79\x20\x74\x68\x69\x6E\x20\x62\x6C\x61\x63\x6B\x20\x62\x65\x61\x72",
	"\x42\x65\x65\x73\x20\x69\x6E\x20\x61\x20\x62\x6F\x74\x74\x6C\x65",
	"\x4C\x61\x72\x67\x65\x20\x73\x6C\x65\x65\x70\x69\x6E\x67\x20\x64\x72\x61\x67\x6F\x6E",
	"\x46\x6C\x69\x6E\x74\x20\x26\x20\x73\x74\x65\x65\x6C",
	"\x2A\x54\x68\x69\x63\x6B\x20\x50\x45\x52\x53\x49\x41\x4E\x20\x52\x55\x47\x2A",
	"\x53\x69\x67\x6E\x3A\x20\x22\x6D\x61\x67\x69\x63\x20\x77\x6F\x72\x64\x27\x73\x20\x41\x57\x41\x59\x21\x20\x4C\x6F\x6F\x6B\x20\x6C\x61\x2E\x2E\x2E\x22\x0A\x28\x52\x65\x73\x74\x20\x6F\x66\x20\x73\x69\x67\x6E\x20\x69\x73\x20\x6D\x69\x73\x73\x69\x6E\x67\x21\x29",
	"\x44\x69\x73\x74\x65\x6E\x64\x65\x64\x20\x67\x61\x73\x20\x62\x6C\x61\x64\x64\x65\x72",
	"\x42\x72\x69\x63\x6B\x65\x64\x20\x75\x70\x20\x77\x69\x6E\x64\x6F\x77",
	"\x53\x69\x67\x6E\x20\x68\x65\x72\x65\x20\x73\x61\x79\x73\x20\x22\x49\x6E\x20\x6D\x61\x6E\x79\x20\x63\x61\x73\x65\x73\x20\x6D\x75\x64\x20\x69\x73\x20\x67\x6F\x6F\x64\x2E\x20\x49\x6E\x20\x6F\x74\x68\x65\x72\x73\x2E\x2E\x2E\x22",
	"\x53\x74\x72\x65\x61\x6D\x20\x6F\x66\x20\x6C\x61\x76\x61",
	"\x42\x72\x69\x63\x6B\x65\x64\x20\x75\x70\x20\x77\x69\x6E\x64\x6F\x77\x20\x77\x69\x74\x68\x20\x61\x20\x68\x6F\x6C\x65\x20\x69\x6E\x20\x69\x74",
	"\x4C\x6F\x6F\x73\x65\x20\x66\x69\x72\x65\x20\x62\x72\x69\x63\x6B\x73",
	"\x2A\x47\x4F\x4C\x44\x20\x43\x52\x4F\x57\x4E\x2A",
	"\x2A\x4D\x41\x47\x49\x43\x20\x4D\x49\x52\x52\x4F\x52\x2A",
	"\x53\x6C\x65\x65\x70\x69\x6E\x67\x20\x62\x65\x61\x72",
	"\x45\x6D\x70\x74\x79\x20\x77\x69\x6E\x65\x20\x62\x6C\x61\x64\x64\x65\x72",
	"\x42\x72\x6F\x6B\x65\x6E\x20\x67\x6C\x61\x73\x73",
	"\x43\x68\x69\x67\x67\x65\x72\x73",
	"\x53\x6C\x69\x67\x68\x74\x6C\x79\x20\x77\x6F\x6F\x7A\x79\x20\x62\x65\x61\x72",
	"\x2A\x44\x52\x41\x47\x4F\x4E\x20\x45\x47\x47\x53\x2A\x20\x28\x76\x65\x72\x79\x20\x72\x61\x72\x65\x29",
	"\x4C\x61\x76\x61\x20\x73\x74\x72\x65\x61\x6D\x20\x77\x69\x74\x68\x20\x62\x72\x69\x63\x6B\x20\x64\x61\x6D",
	"\x2A\x4A\x45\x57\x45\x4C\x45\x44\x20\x46\x52\x55\x49\x54\x2A",
	"\x2A\x53\x6D\x61\x6C\x6C\x20\x73\x74\x61\x74\x75\x65\x20\x6F\x66\x20\x61\x20\x42\x4C\x55\x45\x20\x4F\x58\x2A",
	"\x2A\x44\x49\x41\x4D\x4F\x4E\x44\x20\x52\x49\x4E\x47\x2A",
	"\x2A\x44\x49\x41\x4D\x4F\x4E\x44\x20\x42\x52\x41\x43\x45\x4C\x45\x54\x2A",
	"\x53\x74\x72\x61\x6E\x67\x65\x20\x73\x63\x72\x61\x74\x63\x68\x69\x6E\x67\x73\x20\x6F\x6E\x20\x72\x6F\x63\x6B\x20\x73\x61\x79\x73\x3A\x20\x22\x41\x4C\x41\x44\x49\x4E\x20\x77\x61\x73\x20\x68\x65\x72\x65\x22",
	"\x53\x69\x67\x6E\x20\x73\x61\x79\x73\x20\x22\x4C\x49\x4D\x42\x4F\x2E\x20\x46\x69\x6E\x64\x20\x72\x69\x67\x68\x74\x20\x65\x78\x69\x74\x20\x61\x6E\x64\x20\x6C\x69\x76\x65\x20\x61\x67\x61\x69\x6E\x21\x22",
	"\x53\x6D\x6F\x6B\x69\x6E\x67\x20\x68\x6F\x6C\x65\x2E\x20\x70\x69\x65\x63\x65\x73\x20\x6F\x66\x20\x64\x72\x61\x67\x6F\x6E\x20\x61\x6E\x64\x20\x67\x6F\x72\x65\x2E",
	"\x53\x69\x67\x6E\x20\x73\x61\x79\x73\x20\x22\x4E\x6F\x20\x73\x77\x69\x6D\x6D\x69\x6E\x67\x20\x61\x6C\x6C\x6F\x77\x65\x64\x20\x68\x65\x72\x65\x22",
	"\x41\x72\x72\x6F\x77\x20\x70\x6F\x69\x6E\x74\x69\x6E\x67\x20\x64\x6F\x77\x6E",
	"\x44\x65\x61\x64\x20\x66\x69\x73\x68",
	"\x2A\x46\x49\x52\x45\x53\x54\x4F\x4E\x45\x2A\x20\x28\x63\x6F\x6C\x64\x20\x6E\x6F\x77\x29",
	"\x53\x69\x67\x6E\x20\x73\x61\x79\x73\x20\x22\x50\x61\x75\x6C\x27\x73\x20\x70\x6C\x61\x63\x65\x22",
	"\x54\x72\x65\x65\x73",
	"\x53\x69\x67\x6E\x20\x68\x65\x72\x65\x20\x73\x61\x79\x73\x20\x22\x4F\x70\x70\x6F\x73\x69\x74\x65\x20\x6F\x66\x20\x4C\x49\x47\x48\x54\x20\x69\x73\x20\x55\x4E\x4C\x49\x47\x48\x54\x22",
	"\x45\x6D\x70\x74\x79\x20\x6C\x61\x6D\x70",
	"\x4D\x75\x64\x64\x79\x20\x77\x6F\x72\x74\x68\x6C\x65\x73\x73\x20\x6F\x6C\x64\x20\x72\x75\x67",
	"\x4C\x61\x72\x67\x65\x20\x6F\x75\x74\x64\x6F\x6F\x72\x20\x41\x64\x76\x65\x72\x74\x69\x73\x65\x6D\x65\x6E\x74",
	"\x48\x6F\x6C\x65",
	"",
	"",
};
const uint8_t *msgptr[] = {
	"",
	"\x4E\x6F\x74\x68\x69\x6E\x67\x20\x68\x61\x70\x70\x65\x6E\x73",
	"\x43\x68\x6F\x70\x20\x27\x65\x72\x20\x64\x6F\x77\x6E\x21",
	"\x42\x4F\x59\x20\x74\x68\x61\x74\x20\x72\x65\x61\x6C\x6C\x79\x20\x68\x69\x74\x20\x74\x68\x65\x20\x73\x70\x6F\x74\x21",
	"\x44\x72\x61\x67\x6F\x6E\x20\x73\x6D\x65\x6C\x6C\x73\x20\x73\x6F\x6D\x65\x74\x68\x69\x6E\x67\x2E\x20\x41\x77\x61\x6B\x65\x6E\x73\x20\x26\x20\x61\x74\x74\x61\x63\x6B\x73\x20\x6D\x65\x21",
	"\x4C\x6F\x63\x6B\x20\x73\x68\x61\x74\x74\x65\x72\x73",
	"\x49\x20\x63\x61\x6E\x27\x74\x20\x69\x74\x73\x20\x6C\x6F\x63\x6B\x65\x64",
	"\x54\x49\x4D\x42\x45\x52\x2E\x20\x53\x6F\x6D\x65\x74\x68\x69\x6E\x67\x20\x66\x65\x6C\x6C\x20\x66\x72\x6F\x6D\x20\x74\x68\x65\x20\x74\x72\x65\x65\x20\x74\x6F\x70\x20\x26\x20\x76\x61\x6E\x69\x73\x68\x65\x64\x20\x69\x6E\x20\x74\x68\x65\x20\x73\x77\x61\x6D\x70",
	"\x54\x49\x4D\x42\x45\x52\x21",
	"\x4C\x61\x6D\x70\x20\x69\x73\x20\x6F\x66\x66",
	"\x4C\x61\x6D\x70\x20\x62\x75\x72\x6E\x73\x20\x77\x69\x74\x68\x20\x61\x20\x63\x6F\x6C\x64\x20\x66\x6C\x61\x6D\x65\x6C\x65\x73\x73\x20\x62\x6C\x75\x65\x20\x67\x6C\x6F\x77\x2E",
	"\x49\x27\x6D\x20\x62\x69\x74\x20\x62\x79\x20\x61\x20\x73\x70\x69\x64\x65\x72",
	"\x0A\x4D\x79\x20\x63\x68\x69\x67\x67\x65\x72\x20\x62\x69\x74\x65\x73\x20\x61\x72\x65\x20\x6E\x6F\x77\x20\x49\x4E\x46\x45\x43\x54\x45\x44\x21\x0A",
	"\x4D\x79\x20\x62\x69\x74\x65\x73\x20\x68\x61\x76\x65\x20\x72\x6F\x74\x74\x65\x64\x20\x6D\x79\x20\x77\x68\x6F\x6C\x65\x20\x62\x6F\x64\x79\x21",
	"\x42\x65\x61\x72\x20\x65\x61\x74\x73\x20\x74\x68\x65\x20\x68\x6F\x6E\x65\x79\x20\x61\x6E\x64\x20\x66\x61\x6C\x6C\x73\x20\x61\x73\x6C\x65\x65\x70\x2E",
	"\x42\x65\x65\x73\x20\x73\x74\x69\x6E\x67\x20\x6D\x65",
	"\x46\x69\x72\x73\x74\x20\x49\x20\x6E\x65\x65\x64\x20\x61\x6E\x20\x65\x6D\x70\x74\x79\x20\x63\x6F\x6E\x74\x61\x69\x6E\x65\x72\x2E",
	"\x54\x68\x65\x20\x62\x65\x65\x73\x20\x61\x6C\x6C\x20\x73\x75\x66\x66\x6F\x63\x61\x74\x65\x64\x20\x61\x6E\x64\x20\x64\x69\x73\x61\x70\x70\x65\x61\x72\x65\x64",
	"\x53\x6F\x6D\x65\x74\x68\x69\x6E\x67\x20\x49\x27\x6D\x20\x68\x6F\x6C\x64\x69\x6E\x67\x20\x76\x69\x62\x72\x61\x74\x65\x73\x20\x61\x6E\x64\x2E\x2E\x2E",
	"\x6E\x6F\x74\x68\x69\x6E\x67\x20\x74\x6F\x20\x6C\x69\x67\x68\x74\x20\x69\x74\x20\x77\x69\x74\x68",
	"\x47\x61\x73\x20\x62\x6C\x61\x64\x64\x65\x72\x20\x62\x6C\x65\x77\x20\x75\x70",
	"\x69\x6E\x20\x6D\x79\x20\x68\x61\x6E\x64\x73\x21",
	"\x67\x61\x73\x20\x6E\x65\x65\x64\x73\x20\x74\x6F\x20\x62\x65\x20\x63\x6F\x6E\x74\x61\x69\x6E\x65\x64\x20\x62\x65\x66\x6F\x72\x65\x20\x69\x74\x20\x77\x69\x6C\x6C\x20\x62\x75\x72\x6E",
	"\x47\x61\x73\x20\x64\x69\x73\x73\x69\x70\x61\x74\x65\x73\x2E\x20\x28\x49\x20\x74\x68\x69\x6E\x6B\x20\x79\x6F\x75\x20\x62\x6C\x65\x77\x20\x69\x74\x29",
	"\x54\x68\x61\x74\x20\x77\x6F\x6E\x27\x74\x20\x69\x67\x6E\x69\x74\x65",
	"\x48\x6F\x77\x3F",
	"\x42\x65\x61\x72\x20\x77\x6F\x6E\x27\x74\x20\x6C\x65\x74\x20\x6D\x65",
	"\x22\x44\x6F\x6E\x27\x74\x20\x77\x61\x73\x74\x65\x20\x68\x6F\x6E\x65\x79\x2C\x20\x67\x65\x74\x20\x6D\x61\x64\x20\x69\x6E\x73\x74\x65\x61\x64\x21\x20\x44\x61\x6D\x20\x6C\x61\x76\x61\x21\x3F\x22",
	"\x42\x65\x65\x73\x20\x6D\x61\x64\x64\x65\x6E\x20\x62\x65\x61\x72\x2C\x20\x62\x65\x61\x72\x20\x74\x68\x65\x6E\x20\x61\x74\x74\x61\x63\x6B\x73\x20\x6D\x65\x21",
	"\x49\x74\x20\x73\x6F\x61\x6B\x73\x20\x69\x6E\x74\x6F\x20\x74\x68\x65\x20\x67\x72\x6F\x75\x6E\x64",
	"\x49\x6E\x20\x32\x20\x77\x6F\x72\x64\x73\x20\x74\x65\x6C\x6C\x20\x6D\x65\x20\x61\x74\x20\x77\x68\x61\x74\x2E\x2E\x2E\x6C\x69\x6B\x65\x3A\x20\x41\x54\x20\x54\x52\x45\x45",
	"\x4F\x48\x20\x4E\x4F\x2E\x2E\x2E\x20\x42\x65\x61\x72\x20\x64\x6F\x64\x67\x65\x73\x2E\x2E\x2E\x20\x43\x52\x41\x53\x48\x21",
	"\x49\x74\x73\x20\x68\x65\x61\x76\x79\x21",
	"\x53\x6F\x6D\x65\x74\x68\x69\x6E\x67\x73\x20\x74\x6F\x6F\x20\x68\x65\x61\x76\x79\x2E\x20\x49\x20\x66\x61\x6C\x6C\x2E",
	"\x54\x6F\x20\x73\x74\x6F\x70\x20\x67\x61\x6D\x65\x20\x73\x61\x79\x20\x51\x55\x49\x54",
	"\x4D\x69\x72\x72\x6F\x72\x20\x68\x69\x74\x73\x20\x66\x6C\x6F\x6F\x72\x20\x61\x6E\x64\x20\x73\x68\x61\x74\x74\x65\x72\x73\x20\x69\x6E\x74\x6F\x20\x61\x20\x4D\x49\x4C\x4C\x49\x4F\x4E\x20\x70\x69\x65\x63\x65\x73",
	"\x4D\x69\x72\x72\x6F\x72\x20\x6C\x61\x6E\x64\x73\x20\x73\x6F\x66\x74\x6C\x79\x20\x6F\x6E\x20\x72\x75\x67\x2C\x20\x6C\x69\x67\x68\x74\x73\x20\x75\x70\x20\x61\x6E\x64\x20\x73\x61\x79\x73\x3A",
	"\x59\x6F\x75\x20\x6C\x6F\x73\x74\x20\x2A\x41\x4C\x4C\x2A\x20\x74\x72\x65\x61\x73\x75\x72\x65\x73\x2E",
	"\x49\x27\x6D\x20\x6E\x6F\x74\x20\x63\x61\x72\x72\x79\x69\x6E\x67\x20\x61\x78\x2C\x20\x74\x61\x6B\x65\x20\x69\x6E\x76\x65\x6E\x74\x6F\x72\x79\x21",
	"\x49\x74\x20\x64\x6F\x65\x73\x6E\x27\x74\x20\x73\x65\x65\x6D\x20\x74\x6F\x20\x62\x6F\x74\x68\x65\x72\x20\x68\x69\x6D\x20\x61\x74\x20\x61\x6C\x6C\x21",
	"\x54\x68\x65\x20\x6D\x75\x64\x20\x64\x72\x69\x65\x64\x20\x75\x70\x20\x61\x6E\x64\x20\x66\x65\x6C\x6C\x20\x6F\x66\x66\x2E",
	"\x42\x65\x61\x72\x20\x69\x73\x20\x73\x6F\x20\x73\x74\x61\x72\x74\x6C\x65\x64\x20\x74\x68\x61\x74\x20\x68\x65\x20\x46\x45\x4C\x4C\x20\x6F\x66\x66\x20\x74\x68\x65\x20\x6C\x65\x64\x67\x65\x21",
	"\x22\x20\x44\x52\x41\x47\x4F\x4E\x20\x53\x54\x49\x4E\x47\x20\x22\x20\x61\x6E\x64\x20\x66\x61\x64\x65\x73\x2E\x20\x49\x20\x64\x6F\x6E\x27\x74\x20\x67\x65\x74\x20\x69\x74\x2C\x20\x49\x20\x68\x6F\x70\x65\x20\x79\x6F\x75\x20\x64\x6F\x2E",
	"\x54\x68\x65\x20\x62\x65\x65\x73\x20\x61\x74\x74\x61\x63\x6B\x20\x74\x68\x65\x20\x64\x72\x61\x67\x6F\x6E\x20\x77\x68\x69\x63\x68\x20\x67\x65\x74\x73\x20\x73\x6F\x20\x61\x6E\x6E\x6F\x79\x65\x64\x20\x69\x74\x20\x67\x65\x74\x73\x20\x75\x70\x0A\x61\x6E\x64\x20\x66\x6C\x79\x73\x20\x61\x77\x61\x79\x2E\x2E\x2E",
	"\x4C\x61\x6D\x70\x20\x69\x73\x20\x6E\x6F\x77\x20\x66\x75\x6C\x6C\x20\x26\x20\x6C\x69\x74",
	"\x0A\x49\x27\x6D\x20\x62\x69\x74\x74\x65\x6E\x20\x62\x79\x20\x63\x68\x69\x67\x67\x65\x72\x73\x2E\x0A",
	"\x54\x68\x65\x72\x65\x27\x73\x20\x73\x6F\x6D\x65\x74\x68\x69\x6E\x67\x20\x74\x68\x65\x72\x65\x20\x61\x6C\x6C\x20\x72\x69\x67\x68\x74\x21\x20\x4D\x61\x79\x62\x65\x20\x49\x20\x73\x68\x6F\x75\x6C\x64\x20\x67\x6F\x20\x74\x68\x65\x72\x65\x3F",
	"\x4D\x61\x79\x62\x65\x20\x69\x66\x20\x49\x20\x74\x68\x72\x65\x77\x20\x73\x6F\x6D\x65\x74\x68\x69\x6E\x67\x3F\x2E\x2E\x2E",
	"\x54\x6F\x6F\x20\x64\x72\x79\x2C\x20\x74\x68\x65\x20\x66\x69\x73\x68\x20\x64\x69\x65\x64\x2E",
	"\x41\x20\x67\x6C\x6F\x77\x69\x6E\x67\x20\x47\x65\x6E\x69\x65\x20\x61\x70\x70\x65\x61\x72\x73\x2C\x20\x64\x72\x6F\x70\x73\x20\x73\x6F\x6D\x65\x68\x74\x69\x6E\x67\x2C\x20\x74\x68\x65\x6E\x20\x76\x61\x6E\x69\x73\x68\x65\x73\x2E",
	"\x41\x20\x67\x6C\x6F\x77\x69\x6E\x67\x20\x47\x65\x6E\x69\x65\x20\x61\x70\x70\x65\x61\x72\x73\x2C\x20\x73\x61\x79\x73\x20\x22\x42\x6F\x79\x20\x79\x6F\x75\x27\x72\x65\x20\x73\x65\x6C\x66\x69\x73\x68\x22\x2C\x20\x74\x61\x6B\x65\x73\x0A\x73\x6F\x6D\x65\x74\x68\x69\x6E\x67\x20\x61\x6E\x64\x20\x74\x68\x65\x6E\x20\x6D\x61\x6B\x65\x73\x20\x22\x4D\x45\x22\x20\x76\x61\x6E\x69\x73\x68\x21",
	"\x4E\x6F\x2C\x20\x69\x74\x73\x20\x74\x6F\x6F\x20\x68\x6F\x74\x2E",
	"\x4E\x6F\x74\x20\x68\x65\x72\x65\x2E",
	"\x54\x72\x79\x20\x74\x68\x65\x20\x73\x77\x61\x6D\x70",
	"\x53\x69\x7A\x7A\x6C\x65\x2E\x2E\x2E",
	"\x54\x72\x79\x20\x2D\x2D\x3E\x20\x22\x4C\x4F\x4F\x4B\x2C\x20\x4A\x55\x4D\x50\x2C\x20\x53\x57\x49\x4D\x2C\x20\x43\x4C\x49\x4D\x42\x2C\x20\x46\x49\x4E\x44\x2C\x20\x54\x41\x4B\x45\x2C\x20\x53\x43\x4F\x52\x45\x2C\x20\x44\x52\x4F\x50\x22\x0A\x61\x6E\x64\x20\x61\x6E\x79\x20\x6F\x74\x68\x65\x72\x20\x76\x65\x72\x62\x73\x20\x79\x6F\x75\x20\x63\x61\x6E\x20\x74\x68\x69\x6E\x6B\x20\x6F\x66\x2E\x2E\x2E",
	"\x54\x68\x65\x72\x65\x20\x61\x72\x65\x20\x6F\x6E\x6C\x79\x20\x33\x20\x77\x61\x79\x73\x20\x74\x6F\x20\x77\x61\x6B\x65\x20\x74\x68\x65\x20\x44\x72\x61\x67\x6F\x6E\x21",
	"\x52\x65\x6D\x65\x6D\x62\x65\x72\x20\x79\x6F\x75\x20\x63\x61\x6E\x20\x61\x6C\x77\x61\x79\x73\x20\x73\x61\x79\x20\x22\x48\x45\x4C\x50\x22",
	"\x52\x65\x61\x64\x20\x74\x68\x65\x20\x73\x69\x67\x6E\x20\x69\x6E\x20\x74\x68\x65\x20\x6D\x65\x61\x64\x6F\x77\x21",
	"\x59\x6F\x75\x20\x6D\x61\x79\x20\x6E\x65\x65\x64\x20\x74\x6F\x20\x73\x61\x79\x20\x6D\x61\x67\x69\x63\x20\x77\x6F\x72\x64\x73\x20\x68\x65\x72\x65",
	"\x41\x20\x76\x6F\x69\x63\x65\x20\x42\x4F\x4F\x4F\x4F\x4D\x53\x20\x6F\x75\x74\x3A",
	"\x70\x6C\x65\x61\x73\x65\x20\x6C\x65\x61\x76\x65\x20\x69\x74\x20\x61\x6C\x6F\x6E\x65",
	"\x53\x6F\x72\x72\x79\x2C\x20\x49\x20\x63\x61\x6E\x20\x6F\x6E\x6C\x79\x20\x74\x68\x72\x6F\x77\x20\x74\x68\x65\x20\x61\x78\x2E",
	"\x4D\x65\x64\x69\x63\x69\x6E\x65\x20\x69\x73\x20\x67\x6F\x6F\x64\x20\x66\x6F\x72\x20\x62\x69\x74\x65\x73\x2E",
	"\x49\x20\x64\x6F\x6E\x27\x74\x20\x6B\x6E\x6F\x77\x20\x77\x68\x65\x72\x65\x20\x69\x74\x20\x69\x73",
	"\x0A\x57\x65\x6C\x63\x6F\x6D\x65\x20\x74\x6F\x20\x41\x64\x76\x65\x6E\x74\x75\x72\x65\x20\x6E\x75\x6D\x62\x65\x72\x3A\x20\x31\x20\x22\x41\x44\x56\x45\x4E\x54\x55\x52\x45\x4C\x41\x4E\x44\x22\x2E\x0A\x49\x6E\x20\x74\x68\x69\x73\x20\x41\x64\x76\x65\x6E\x74\x75\x72\x65\x20\x79\x6F\x75\x27\x72\x65\x20\x74\x6F\x20\x66\x69\x6E\x64\x20\x2A\x54\x52\x45\x41\x53\x55\x52\x45\x53\x2A\x20\x26\x20\x73\x74\x6F\x72\x65\x20\x74\x68\x65\x6D\x20\x61\x77\x61\x79\x2E\x0A\x0A\x54\x6F\x20\x73\x65\x65\x20\x68\x6F\x77\x20\x77\x65\x6C\x6C\x20\x79\x6F\x75\x27\x72\x65\x20\x64\x6F\x69\x6E\x67\x20\x73\x61\x79\x3A\x20\x22\x53\x43\x4F\x52\x45\x22",
	"\x42\x6C\x6F\x77\x20\x69\x74\x20\x75\x70\x21",
	"\x46\x69\x73\x68\x20\x68\x61\x76\x65\x20\x65\x73\x63\x61\x70\x65\x64\x20\x62\x61\x63\x6B\x20\x74\x6F\x20\x74\x68\x65\x20\x6C\x61\x6B\x65\x2E",
	"\x4F\x4B",
	"\x48\x75\x68\x3F\x20\x49\x20\x64\x6F\x6E\x27\x74\x20\x74\x68\x69\x6E\x6B\x20\x73\x6F\x21",
	"\x59\x6F\x75\x20\x6D\x69\x67\x68\x74\x20\x74\x72\x79\x20\x65\x78\x61\x6D\x69\x6E\x69\x6E\x67\x20\x74\x68\x69\x6E\x67\x73\x2E\x2E\x2E",
	"\x57\x68\x61\x74\x3F",
	"\x4F\x4B\x2C\x20\x49\x20\x74\x68\x72\x65\x77\x20\x69\x74\x2E",
	"\x0A\x43\x68\x65\x63\x6B\x20\x77\x69\x74\x68\x20\x79\x6F\x75\x72\x20\x66\x61\x76\x6F\x72\x69\x74\x65\x20\x63\x6F\x6D\x70\x75\x74\x65\x72\x20\x64\x65\x61\x6C\x65\x72\x20\x66\x6F\x72\x20\x74\x68\x65\x20\x6E\x65\x78\x74\x20\x41\x64\x76\x65\x6E\x74\x75\x72\x65\x0A\x70\x72\x6F\x67\x72\x61\x6D\x3A\x20\x50\x49\x52\x41\x54\x45\x20\x41\x44\x56\x45\x4E\x54\x55\x52\x45\x2E\x20\x49\x66\x20\x74\x68\x65\x79\x20\x64\x6F\x6E\x27\x74\x20\x63\x61\x72\x72\x79\x20\x22\x41\x44\x56\x45\x4E\x54\x55\x52\x45\x22\x20\x68\x61\x76\x65\x0A\x74\x68\x65\x6D\x20\x63\x61\x6C\x6C\x3A\x20\x31\x2D\x33\x30\x35\x2D\x38\x36\x32\x2D\x36\x39\x31\x37\x20\x74\x6F\x64\x61\x79\x21\x0A",
	"\x54\x68\x65\x20\x61\x78\x20\x76\x69\x62\x72\x61\x74\x65\x64\x21",
	"\x49\x20\x73\x65\x65\x20\x6E\x6F\x74\x68\x69\x6E\x67\x20\x73\x70\x65\x63\x69\x61\x6C",
};


const uint8_t status[] = {
	145, 75, 
	1, 8, 6, 19, 0, 8, 0, 10, 
	117, 62, 
	137, 10, 
	1, 21, 7, 33, 
	13, 61, 
	146, 10, 
	1, 20, 0, 21, 0, 20, 6, 7, 
	12, 74, 59, 
	145, 8, 
	3, 26, 0, 26, 0, 13, 9, 17, 
	17, 72, 
	183, 
	8, 5, 0, 38, 0, 41, 0, 21, 0, 5, 
	55, 62, 60, 64, 
	165, 
	4, 24, 
	37, 63, 
	145, 5, 
	1, 7, 0, 7, 0, 1, 6, 12, 
	40, 62, 
	149, 8, 
	6, 20, 6, 21, 0, 20, 2, 42, 6, 7, 
	74, 45, 
	137, 8, 
	2, 24, 12, 7, 
	15, 61, 
	169, 
	4, 5, 8, 15, 
	57, 76, 
	146, 50, 
	1, 8, 6, 12, 0, 8, 0, 55, 
	48, 59, 52, 
	178, 
	8, 7, 0, 7, 0, 47, 0, 25, 
	60, 62, 66, 
	149, 30, 
	1, 42, 6, 21, 6, 20, 0, 20, 6, 7, 
	74, 45, 
	138, 50, 
	2, 27, 3, 7, 
	70, 4, 61, 
	182, 
	8, 12, 2, 32, 0, 36, 0, 32, 0, 35, 
	53, 55, 53, 
	177, 
	8, 12, 2, 27, 0, 52, 0, 27, 
	53, 55, 
	178, 
	8, 1, 9, 2, 0, 1, 0, 2, 
	42, 60, 58, 
	174, 
	8, 14, 0, 13, 0, 14, 
	74, 60, 61, 
	169, 
	8, 12, 0, 12, 
	64, 60, 
	171, 
	9, 13, 0, 13, 
	110, 58, 115, 107, 
	178, 
	8, 1, 8, 2, 0, 1, 0, 2, 
	27, 60, 60, 
	178, 
	0, 16, 8, 16, 0, 60, 0, 9, 
	60, 72, 76, 
	176, 
	4, 26, 3, 29, 0, 29, 0, 61, 
	72, 
};
const uint8_t actions[] = {
	4, 29, 54, 
	2, 34, 
	46, 
	4, 29, 57, 
	2, 4, 
	46, 
	19, 10, 21, 
	2, 7, 1, 21, 0, 21, 0, 7, 
	59, 52, 118, 3, 
	13, 10, 42, 
	2, 23, 6, 7, 2, 24, 
	15, 61, 
	19, 10, 21, 
	2, 7, 1, 20, 0, 20, 0, 7, 
	59, 52, 118, 3, 
	23, 18, 42, 
	1, 23, 0, 23, 2, 25, 0, 39, 0, 25, 
	59, 14, 53, 55, 
	8, 18, 42, 
	1, 23, 0, 23, 
	53, 
	9, 10, 23, 
	2, 24, 6, 7, 
	15, 61, 
	12, 10, 23, 
	2, 24, 1, 7, 6, 13, 
	16, 
	21, 10, 23, 
	2, 24, 1, 7, 1, 13, 0, 13, 0, 26, 
	72, 118, 
	0, 10, 33, 
	66, 
	4, 56, 54, 
	4, 18, 
	51, 
	0, 34, 0, 
	66, 
	15, 48, 9, 
	1, 29, 4, 17, 0, 23, 
	54, 18, 57, 64, 
	4, 14, 0, 
	6, 28, 
	19, 
	15, 14, 25, 
	1, 31, 1, 28, 0, 31, 
	20, 21, 61, 59, 
	9, 58, 16, 
	3, 26, 0, 17, 
	58, 118, 
	19, 14, 25, 
	2, 31, 1, 28, 0, 31, 0, 12, 
	70, 55, 58, 20, 
	14, 1, 34, 
	4, 20, 2, 35, 0, 19, 
	54, 70, 64, 
	8, 10, 25, 
	4, 1, 6, 40, 
	16, 
	17, 10, 25, 
	4, 1, 1, 40, 0, 40, 0, 31, 
	72, 118, 
	14, 18, 25, 
	1, 31, 0, 31, 0, 40, 
	72, 118, 23, 
	8, 14, 25, 
	2, 18, 1, 28, 
	22, 
	0, 45, 53, 
	114, 
	4, 1, 35, 
	4, 19, 
	25, 
	13, 10, 10, 
	2, 38, 0, 38, 5, 25, 
	52, 118, 
	18, 18, 10, 
	1, 38, 0, 38, 2, 29, 0, 1, 
	53, 36, 58, 
	9, 42, 43, 
	1, 46, 0, 46, 
	3, 59, 
	18, 10, 13, 
	2, 6, 1, 13, 0, 13, 0, 12, 
	59, 52, 118, 
	13, 6, 0, 
	4, 19, 0, 21, 6, 36, 
	54, 64, 
	9, 6, 0, 
	4, 21, 0, 19, 
	54, 64, 
	8, 1, 35, 
	4, 21, 2, 25, 
	26, 
	14, 1, 35, 
	4, 21, 5, 25, 0, 22, 
	54, 70, 64, 
	22, 58, 54, 
	3, 36, 0, 0, 0, 34, 0, 45, 2, 34, 
	72, 53, 76, 
	4, 1, 54, 
	4, 18, 
	51, 
	23, 18, 23, 
	1, 26, 2, 25, 0, 26, 0, 24, 0, 14, 
	28, 59, 53, 58, 
	8, 10, 13, 
	2, 6, 6, 13, 
	16, 
	4, 38, 51, 
	2, 3, 
	2, 
	10, 1, 57, 
	0, 2, 2, 5, 
	54, 70, 64, 
	18, 18, 13, 
	1, 12, 0, 12, 0, 13, 7, 18, 
	72, 118, 29, 
	19, 55, 17, 
	3, 22, 1, 60, 0, 22, 0, 60, 
	59, 59, 44, 69, 
	22, 8, 57, 
	0, 5, 2, 5, 12, 14, 0, 4, 1, 11, 
	55, 53, 7, 
	12, 69, 20, 
	4, 5, 2, 16, 6, 14, 
	6, 
	12, 37, 20, 
	4, 5, 2, 16, 6, 14, 
	6, 
	14, 24, 11, 
	1, 11, 0, 3, 0, 11, 
	30, 58, 53, 
	18, 69, 20, 
	2, 16, 1, 14, 0, 16, 0, 17, 
	55, 53, 76, 
	0, 56, 0, 
	25, 
	9, 6, 0, 
	4, 19, 1, 36, 
	33, 61, 
	22, 57, 54, 
	3, 36, 0, 0, 0, 34, 0, 45, 2, 34, 
	72, 53, 76, 
	10, 10, 37, 
	2, 36, 0, 36, 
	52, 118, 32, 
	0, 32, 0, 
	34, 
	1, 26, 0, 
	65, 63, 
	8, 10, 10, 
	2, 38, 2, 25, 
	26, 
	18, 18, 10, 
	1, 38, 5, 29, 0, 41, 0, 38, 
	35, 53, 59, 
	15, 7, 38, 
	8, 3, 5, 38, 0, 3, 
	122, 110, 111, 60, 
	14, 7, 39, 
	8, 3, 0, 3, 2, 27, 
	122, 39, 60, 
	0, 33, 0, 
	65, 
	7, 47, 0, 
	1, 20, 
	70, 110, 113, 105, 
	7, 47, 0, 
	1, 21, 
	70, 110, 113, 105, 
	4, 1, 34, 
	4, 18, 
	102, 
	4, 10, 54, 
	2, 34, 
	51, 
	18, 51, 0, 
	2, 25, 0, 43, 0, 18, 0, 25, 
	41, 62, 55, 
	23, 18, 23, 
	1, 26, 2, 27, 0, 24, 0, 44, 0, 27, 
	53, 53, 55, 43, 
	11, 7, 19, 
	8, 3, 0, 3, 
	60, 1, 110, 107, 
	4, 69, 20, 
	2, 17, 
	64, 
	10, 1, 16, 
	2, 35, 0, 19, 
	70, 54, 64, 
	23, 7, 38, 
	8, 3, 0, 38, 0, 5, 0, 4, 2, 38, 
	55, 58, 31, 60, 
	1, 45, 11, 
	110, 114, 
	1, 36, 0, 
	1, 47, 
	10, 1, 57, 
	2, 4, 0, 3, 
	54, 70, 64, 
	22, 8, 57, 
	2, 5, 1, 11, 0, 5, 0, 4, 1, 14, 
	55, 53, 8, 
	5, 39, 38, 
	2, 25, 
	26, 47, 
	5, 39, 39, 
	2, 27, 
	39, 47, 
	14, 42, 13, 
	1, 12, 0, 12, 0, 13, 
	3, 59, 52, 
	4, 42, 13, 
	2, 6, 
	3, 
	9, 42, 42, 
	3, 23, 0, 23, 
	3, 59, 
	23, 7, 20, 
	2, 16, 8, 3, 0, 16, 0, 17, 0, 3, 
	55, 53, 5, 60, 
	8, 27, 0, 
	4, 26, 10, 0, 
	33, 
	14, 27, 0, 
	4, 26, 11, 0, 0, 10, 
	54, 70, 64, 
	4, 8, 0, 
	6, 11, 
	38, 
	23, 48, 32, 
	3, 47, 1, 11, 0, 11, 0, 25, 0, 7, 
	85, 18, 62, 58, 
	19, 48, 32, 
	1, 11, 7, 26, 0, 11, 0, 25, 
	85, 18, 62, 66, 
	4, 28, 17, 
	3, 9, 
	51, 
	9, 10, 21, 
	2, 7, 0, 7, 
	52, 118, 
	18, 28, 17, 
	3, 10, 9, 8, 0, 48, 0, 8, 
	49, 53, 58, 
	8, 28, 17, 
	3, 10, 8, 11, 
	1, 
	19, 28, 17, 
	3, 10, 8, 10, 0, 11, 0, 48, 
	50, 58, 61, 59, 
	19, 28, 17, 
	3, 10, 8, 9, 0, 10, 0, 49, 
	50, 58, 61, 59, 
	18, 28, 17, 
	3, 10, 8, 8, 0, 49, 0, 9, 
	49, 53, 58, 
	14, 51, 0, 
	1, 20, 0, 20, 0, 21, 
	3, 12, 72, 
	6, 51, 0, 
	1, 21, 
	3, 13, 61, 
	4, 27, 0, 
	7, 26, 
	102, 
	0, 60, 0, 
	1, 
	6, 48, 32, 
	2, 11, 
	118, 85, 124, 
	4, 14, 17, 
	3, 9, 
	10, 
	0, 45, 57, 
	103, 
	18, 18, 23, 
	1, 26, 0, 24, 0, 26, 0, 13, 
	53, 72, 118, 
	0, 45, 30, 
	103, 
	0, 45, 21, 
	103, 
	22, 7, 60, 
	8, 3, 0, 3, 4, 26, 0, 11, 0, 10, 
	60, 62, 118, 
	10, 1, 57, 
	4, 11, 0, 28, 
	54, 70, 64, 
	6, 47, 0, 
	4, 26, 
	110, 105, 109, 
	5, 47, 0, 
	4, 11, 
	110, 105, 
	5, 47, 0, 
	4, 19, 
	110, 105, 
	5, 47, 0, 
	4, 23, 
	110, 106, 
	5, 47, 0, 
	4, 13, 
	110, 109, 
	5, 47, 0, 
	4, 17, 
	110, 109, 
	5, 47, 0, 
	4, 15, 
	110, 109, 
	5, 47, 0, 
	4, 21, 
	110, 105, 
	5, 47, 0, 
	4, 8, 
	110, 108, 
	17, 37, 20, 
	1, 14, 2, 16, 0, 17, 0, 16, 
	53, 55, 
	11, 1, 56, 
	2, 17, 0, 6, 
	54, 56, 70, 64, 
	14, 14, 17, 
	3, 10, 0, 10, 0, 9, 
	72, 10, 76, 
	15, 37, 17, 
	3, 9, 0, 9, 0, 10, 
	72, 118, 9, 76, 
	5, 10, 51, 
	2, 3, 
	11, 61, 
	10, 1, 16, 
	2, 52, 0, 24, 
	54, 70, 64, 
	1, 10, 49, 
	110, 111, 
	8, 14, 0, 
	1, 28, 5, 18, 
	24, 
	0, 51, 0, 
	1, 
	23, 48, 9, 
	1, 29, 7, 17, 0, 17, 7, 33, 7, 26, 
	54, 18, 56, 64, 
	5, 47, 0, 
	4, 1, 
	110, 105, 
	4, 24, 11, 
	6, 11, 
	38, 
	6, 47, 0, 
	4, 20, 
	110, 116, 103, 
	2, 48, 32, 
	118, 85, 1, 
	10, 1, 16, 
	4, 4, 0, 5, 
	54, 70, 64, 
	9, 10, 42, 
	2, 23, 0, 23, 
	52, 118, 
	1, 47, 0, 
	1, 120, 
	1, 8, 0, 
	1, 47, 
	0, 24, 0, 
	112, 
	10, 7, 0, 
	8, 3, 0, 3, 
	60, 122, 1, 
	1, 35, 65, 
	118, 71, 
	0, 28, 0, 
	1, 
	2, 48, 0, 
	118, 85, 1, 
	0, 42, 0, 
	119, 
	18, 18, 13, 
	1, 12, 4, 18, 0, 12, 0, 13, 
	104, 73, 72, 
	200, 
	2, 0, 0, 56, 
	72, 
	4, 10, 59, 
	2, 0, 
	51, 
	9, 10, 59, 
	2, 56, 0, 56, 
	118, 52, 
	0, 45, 0, 
	114, 
	5, 38, 62, 
	3, 62, 
	70, 123, 
	0, 29, 16, 
	46, 
	0, 6, 0, 
	102, 
	0, 39, 18, 
	114, 
	0, 39, 0, 
	25, 
	2, 29, 0, 
	118, 125, 76, 
	0, 7, 0, 
	121, 
	9, 1, 16, 
	4, 29, 0, 30, 
	54, 76, 
	255,
};


const uint8_t verbs[] = {
65, 85, 84,
71, 79, 32,
197, 78, 84,
210, 85, 78,
215, 65, 76,
195, 76, 73,
74, 85, 77,
65, 84, 32,
67, 72, 79,
195, 85, 84,
71, 69, 84,
212, 65, 75,
208, 73, 67,
195, 65, 84,
76, 73, 71,
174, 32, 32,
201, 71, 78,
194, 85, 82,
68, 82, 79,
210, 69, 76,
211, 80, 73,
204, 69, 65,
199, 73, 86,
208, 79, 85,
84, 72, 82,
212, 79, 83,
81, 85, 73,
83, 87, 73,
82, 85, 66,
76, 79, 79,
197, 88, 65,
196, 69, 83,
83, 84, 79,
83, 67, 79,
73, 78, 86,
83, 65, 86,
87, 65, 75,
85, 78, 76,
82, 69, 65,
65, 84, 84,
211, 76, 65,
203, 73, 76,
68, 82, 73,
197, 65, 84,
46, 32, 32,
70, 73, 78,
204, 79, 67,
72, 69, 76,
83, 65, 89,
211, 80, 69,
195, 65, 76,
83, 67, 82,
217, 69, 76,
200, 79, 76,
46, 32, 32,
70, 73, 76,
67, 82, 79,
68, 65, 77,
77, 65, 75,
194, 85, 73,
87, 65, 86,
212, 73, 67,
203, 73, 67,
203, 73, 83,
212, 79, 85,
198, 69, 69,
198, 85, 67,
200, 73, 84,
208, 79, 75,
79, 80, 69,
	0,
};
const uint8_t nouns[] = {
65, 78, 89,
78, 79, 82,
83, 79, 85,
69, 65, 83,
87, 69, 83,
85, 80, 32,
68, 79, 87,
78, 69, 84,
70, 73, 83,
65, 87, 65,
77, 73, 82,
65, 88, 69,
193, 88, 32,
87, 65, 84,
66, 79, 84,
195, 79, 78,
72, 79, 76,
76, 65, 77,
83, 80, 73,
87, 73, 78,
68, 79, 79,
77, 85, 68,
205, 69, 68,
66, 69, 69,
82, 79, 67,
71, 65, 83,
70, 76, 73,
69, 71, 71,
79, 73, 76,
211, 76, 73,
75, 69, 89,
72, 69, 76,
66, 85, 78,
73, 78, 86,
76, 69, 68,
84, 72, 82,
67, 82, 79,
66, 82, 73,
66, 69, 65,
68, 82, 65,
82, 85, 71,
82, 85, 66,
72, 79, 78,
70, 82, 85,
79, 88, 32,
82, 73, 78,
67, 72, 73,
194, 73, 84,
66, 82, 65,
83, 73, 71,
66, 76, 65,
87, 69, 66,
215, 82, 73,
83, 87, 65,
76, 65, 86,
196, 65, 77,
72, 65, 76,
84, 82, 69,
211, 84, 85,
70, 73, 82,
83, 72, 79,
194, 65, 78,
65, 68, 86,
71, 76, 65,
65, 82, 79,
71, 65, 77,
66, 79, 79,
67, 72, 65,
76, 65, 75,
89, 79, 72,
	0,
};
const uint8_t automap[] = {
82, 85, 66,
	2,
77, 85, 68,
	7,
70, 73, 83,
	8,
76, 65, 77,
	9,
76, 65, 77,
	10,
65, 88, 69,
	11,
66, 79, 84,
	12,
66, 79, 84,
	13,
75, 69, 89,
	14,
78, 69, 84,
	19,
79, 73, 76,
	22,
72, 79, 78,
	23,
66, 79, 84,
	26,
70, 76, 73,
	28,
82, 85, 71,
	29,
66, 76, 65,
	31,
66, 82, 73,
	36,
67, 82, 79,
	37,
66, 76, 65,
	40,
71, 76, 65,
	41,
67, 72, 73,
	42,
69, 71, 71,
	44,
70, 82, 85,
	46,
79, 88, 32,
	47,
82, 73, 78,
	48,
66, 82, 65,
	49,
70, 73, 83,
	55,
70, 73, 82,
	56,
76, 65, 77,
	60,
82, 85, 71,
	61,
65, 68, 86,
	62,
	0,
};
#include <stdio.h>	/* Not really used but needed for perror */
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>
#include <setjmp.h>
#include <termios.h>

#ifdef __linux__
#include <stdio.h>
#endif

static jmp_buf restart;

struct savearea {
  uint16_t magic;
  uint8_t carried;
  uint8_t lighttime;
  uint8_t location;
  uint8_t objloc[NUM_OBJ];
  uint8_t roomsave[6];
  uint8_t savedroom;
  uint32_t bitflags;
  int16_t counter;
  int16_t counter_array[16];
};

static char linebuf[81];
static char *nounbuf;
static char wordbuf[WORDSIZE + 1];

static uint8_t verb;
static uint8_t noun;
static const uint8_t *linestart;
static uint8_t linematch;
static uint8_t actmatch;
static uint8_t continuation;
static uint16_t *param;
static uint16_t param_buf[5];
static uint8_t rows, cols;
static uint8_t redraw;

static struct savearea game;

static void error(const char *p);

#define VERB_GO		1
#define VERB_GET	10
#define VERB_DROP	18

#define LIGHTOUT	16
#define DARKFLAG	15
#define LIGHT_SOURCE	9

/* Define this because 1 << n might be 16bit */
#define ONEBIT		((uint32_t)1)

#define REDRAW		1
#define REDRAW_MAYBE	2

#ifdef CONFIG_IO_CURSES

#include <curses.h>

#define REDRAW_MASK	(REDRAW|REDRAW_MAYBE)

static char wbuf[81];
static int wbp = 0;
static int xpos = 0, ypos = 0;
static int bottom;
static WINDOW *topwin, *botwin, *curwin;

static void flush_word(void)
{
  wbuf[wbp] = 0;
  waddstr(curwin, wbuf);
  xpos += wbp;
  wbp = 0;
}

static void new_line(void)
{
  xpos = 0;
  if (curwin == topwin)
    ypos++;
  else {
    scroll(curwin);
    ypos = bottom;
  }
  wmove(curwin, ypos, xpos);
}

static void char_out(char c)
{
  if (c == '\n') {
    flush_word();
    new_line();
    return;
  }
  if (c != ' ') {
    if (wbp < 80)
      wbuf[wbp++] = c;
    return;
  }
  if (xpos + wbp >= cols)
    new_line();
  flush_word();
  waddch(curwin, ' ');
  xpos++;
}

static void strout_lower(const uint8_t *p)
{
  while(*p)
    char_out(*p++);
}

static void strout_lower_spc(const uint8_t *p)
{
  strout_lower(p);
  char_out(' ');
}

static void decout_lower(uint16_t v)
{
#ifdef __linux__
  char buf[9];
  snprintf(buf, 8, "%d", v);	/* FIXME: avoid expensive snprintf */
  strout_lower((uint8_t *)buf);
#else
  strout_lower((uint8_t *)_itoa(v));
#endif
}

static void strout_upper(const uint8_t *p)
{
  strout_lower(p);
}

static char readchar(void)
{
  wrefresh(botwin);
  return wgetch(botwin);
}

static void line_input(int m)
{
  int c;
  char *p = linebuf;

  do {
    wmove(botwin, ypos, xpos);
    wrefresh(botwin);
    c = wgetch(botwin);
    if (c == 8 || c == 127) {
      if (p > linebuf) {
        xpos--;
        mvwaddch(botwin, ypos, xpos, ' ');
        p--;
      }
      continue;
    }
    if (c > 31 && c < 127) {
      if (p < linebuf + 80 && xpos < cols - 1) {
        *p++ = c;
        mvwaddch(botwin, ypos, xpos, c);
        xpos++;
      }
      continue;
    }
  }
  while (c != 13 && c != 10);
  *p = 0;
  new_line();
}

static int saved_x;

static void begin_upper(void)
{
  saved_x = xpos;
  curwin = topwin;
  werase(topwin);
  ypos = 0;
  xpos = 0;
}

static void end_upper(void)
{
  flush_word();
  curwin = botwin;
  xpos = saved_x;
  ypos = bottom;
  wrefresh(topwin);
}

static void display_init(void)
{
  int trow;

  initscr();
  noecho();
  cbreak();
  nonl();

  getmaxyx(stdscr, rows, cols);

  if (rows < 16)
    error("display too small");

  trow = 10;
  if (rows / 2 < 10)
    trow = rows / 2;
  bottom = rows - trow;

  topwin = newwin(trow, cols, 0, 0);
  botwin = newwin(bottom--, cols, trow, 0);
  if (!topwin || !botwin)
    error("curses");
  scrollok(botwin, TRUE);
  curwin = botwin;
  new_line();
}

static void display_exit(void)
{
  endwin();
}

#elif defined(CONFIG_IO_CUSS)

/* ---- */

#include <termcap.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <sys/wait.h>
#include <termios.h>

/* A mini look alike to David Given's libcuss. If useful will probably
   become a library. For now pasted around to experiment */

uint_fast8_t screenx, screeny, screen_height, screen_width;

static char *t_go, *t_clreol, *t_clreos;
static uint8_t conbuf[64];
static uint8_t *conp = conbuf;

extern void con_puts(const char *s);

/* Queue a character to the output buffer */
static int conq(int c)
{
	if (conp == conbuf + sizeof(conbuf)) {
		write(1, conbuf, sizeof(conbuf));
		conp = conbuf;
	}
	*conp++ = (uint8_t) c;
	return 0;
}

/* Make sure the output buffer is written */
void con_flush(void)
{
	write(1, conbuf, conp - conbuf);
	conp = conbuf;
}

static const char hex[] = "0123456789ABCDEF";

/* Put a character to the screen. We handle unprintables and tabs */
void con_putc(uint8_t c)
{
	if (c == '\t') {
		uint8_t n = 8 - (screenx & 7);
		while (n--)
			con_putc(' ');
		return;
	}
	if (c > 127) {
		con_puts("\\x");
		con_putc(hex[c >> 4]);
		con_putc(hex[c & 0x0F]);
		return;
	} else if (c == 127) {
		con_puts("^?");
		return;
	}
	if (c < 32) {
		con_putc('^');
		c += '@';
	}
	conq(c);
	screenx++;
adjust:
	if (screenx == screen_width) {
		screenx = 0;
		screeny++;
	}
}

/* Write a termcap string out */
static void con_twrite(char *p, int n)
{
#if !defined(__linux__)
	tputs(p, n, conq);
#else
	while (*p)
		conq(*p++);
#endif
}

/* Write a string of symbols including quoting */
void con_puts(const char *s)
{
	uint8_t c;
	while (c = (uint8_t) *s++)
		con_putc(c);
}

/* Add a newline */
void con_newline(void)
{
	if (screeny >= screen_height)
		return;
	conq('\n');
	screenx = 0;
	screeny++;
}

/* We need to optimize this but firstly we need to fix our
   tracking logic as we use con_goto internally but don't track
   that verus the true user values */
void con_force_goto(uint_fast8_t y, uint_fast8_t x)
{
	con_twrite(tgoto(t_go, x, y), 2);
	screenx = x;
	screeny = y;
}

void con_goto(uint_fast8_t y, uint_fast8_t x)
{
#if 0
	if (screenx == x && screeny == y)
		return;
	if (screeny == y && x == 0) {
		conq('\r');
		screenx = 0;
		return;
	}
	if (screeny == y - 1 && x == 0) {
		con_newline();
		return;
	}
#endif	
	con_force_goto(y, x);
}

/* Clear to end of line */
void con_clear_to_eol(void)
{
	if (screenx == screen_width - 1)
		return;
	if (t_clreol)
		con_twrite(t_clreol, 1);
	else {
		uint_fast8_t i;
		/* Write spaces. This tends to put the cursor where
		   we want it next time too. Might be worth optimizing ? */
		for (i = screenx; i < screen_width; i++)
			con_putc(' ');
	}
}

/* Clear to the bottom of the display */

void con_clear_to_bottom(void)
{
	/* Most terminals have a clear to end of screen */
	if (t_clreos)
		con_twrite(t_clreos, screen_height);
	/* If not then clear each line, which may in turn emit
	   a lot of spaces in desperation */
	else {
		uint_fast8_t i;
		for (i = 0; i < screen_height; i++) {
			con_goto(i, 0);
			con_clear_to_eol();
		}
	}
	con_force_goto(0, 0);
}

void con_clear(void)
{
	con_goto(0, 0);
	con_clear_to_bottom();
}

int con_scroll(int n)
{
	if (n == 0)
		return 0;
	/* For now we don't do backscrolls: FIXME */
	if (n < 0)
		return 1;
	/* Scrolling down we can do */
	con_force_goto(screen_height - 1, 0);
	while (n--)
		conq('\n');
	con_force_goto(screeny, screenx);
}

/* TODO: cursor key handling */
int con_getch(void)
{
	uint8_t c;
	con_flush();
	if (read(0, &c, 1) != 1)
		return -1;
	return c;
}

int con_size(uint8_t c)
{
	if (c == '\t')
		return 8 - (screenx & 7);
	/* We will leave unicode out 8) */
	if (c > 127)
		return 4;
	if (c < 32 || c == 127)
		return 2;
	return 1;
}

static int do_read(int fd, void *p, int len)
{
	int l;
	if ((l = read(fd, p, len)) != len) {
		if (l < 0)
			perror("read");
		else
			write(2, "short read from tchelp.\n", 25);
		return -1;
	}
	return 0;
}

static char *tnext(char *p)
{
	return p + strlen(p) + 1;
}

static int tty_init(void)
{
	int fd[2];
	pid_t pid;
	int ival[3];
	int n;
	int status;

	if (pipe(fd) < 0) {
		perror("pipe");
		return -1;
	}

	pid = fork();
	if (pid == -1) {
		perror("fork");
		return -1;
	}

	if (pid == 0) {
		close(fd[0]);
		dup2(fd[1], 1);
		execl("/usr/lib/tchelp", "tchelp", "li#co#cm$ce$cd$cl$", NULL);
		perror("tchelp");
		_exit(1);
	}
	close(fd[1]);
	waitpid(pid, &status, 0);

	do_read(fd[0], ival, sizeof(int));
	if (ival[0] == 0)
		return -1;
	do_read(fd[0], ival + 1, 2 * sizeof(int));

	ival[0] -= 2 * sizeof(int);
	t_go = sbrk((ival[0] + 3) & ~3);

	if (t_go == (void *) -1) {
		perror("sbrk");
		return -1;
	}

	if (do_read(fd[0], t_go, ival[0]))
		return -1;

	close(fd[0]);
	t_clreol = tnext(t_go);
	t_clreos = tnext(t_clreol);
	if (*t_clreos == 0)	/* No clr eos - try for clr/home */
		t_clreos++;	/* cl cap if present */
	if (*t_go == 0) {
		write(2, "Insufficient terminal features.\n", 32);
		return -1;
	}
	/* TODO - screen sizes */
	screen_height = ival[1];
	screen_width = ival[2];
	/* need to try WINSZ and VT ioctls */
	return 0;
}

static struct termios con_termios, old_termios;

void con_exit(void)
{
	tcsetattr(0, TCSANOW, &old_termios);
}

int con_init(void)
{
	int n;
	static struct winsize w;
	if (tty_init())
		return -1;
	if (tcgetattr(0, &con_termios) == -1)
		return -1;
	memcpy(&old_termios, &con_termios, sizeof(struct termios));
	atexit(con_exit);
	con_termios.c_lflag &= ~(ICANON | ECHO | ISIG);
	con_termios.c_iflag &= ~(IXON);
	con_termios.c_cc[VMIN] = 1;
	con_termios.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSANOW, &con_termios) == -1)
		return -1;
#ifdef VTSIZE
	n = ioctl(0, VTSIZE, 0);
	if (n != -1) {
		screen_width = n & 0xFF;
		screen_height = (n >> 8) & 0xFF;
	}
#endif
	if (ioctl(0, TIOCGWINSZ, &w) == 0) {
		if (w.ws_col)
			screen_width = w.ws_col;
		if (w.ws_row)
			screen_height = w.ws_row;
	}
	return 0;
}


/* ---- */

/* Glue to the library */

#define REDRAW_MASK	0

static char wbuf[81];
static int wbp = 0;
static int upper;

static void display_exit(void)
{
  con_newline();
  con_flush();
}

static void display_init(void)
{
  if (con_init())
    exit(1);
  con_clear();
  con_goto(screen_height - 1, 0);
}

static void flush_word(void)
{
  if (screenx)
    con_putc(' ');
  wbuf[wbp] = 0;
  con_puts(wbuf);
  wbp = 0;
}

static void move_on(void)
{
    /* Move on a line in the correct manner */
    if (upper) {
      con_clear_to_eol();
      con_newline();
    } else {
      con_scroll(1);
      con_goto(screen_height - 1, 0);
    }
}

static void char_out(char c)
{
  if (c != ' ' && c != '\n') {
    if (wbp < 80)
      wbuf[wbp++] = c;
    return;
  }
  /* Does the word not fit ? */
  if (screenx + wbp + 1 >= screen_width)
    move_on();
  /* Write out the word */
  flush_word();
  if (c == '\n')
    move_on();
}

static void strout_lower(const uint8_t *p)
{
  while(*p)
    char_out(*p++);
}

static void strout_lower_spc(const uint8_t *p)
{
  strout_lower(p);
  char_out(' ');
}

static void decout_lower(uint16_t v)
{
#ifdef __linux__
  char buf[9];
  snprintf(buf, 8, "%d", v);	/* FIXME: avoid expensive snprintf */
  strout_lower((uint8_t *)buf);
#else
  strout_lower((uint8_t *)_itoa(v));
#endif
}

static void strout_upper(const uint8_t *p)
{
  strout_lower(p);
}

static void action_look(void);

static void line_input(int m)
{
  int c;
  char *p = linebuf;

  if (m == 0)
    action_look();

  do {
    c = con_getch();
    if (c == 8 || c == 127) {
      if (p > linebuf) {
        con_goto(screen_height - 1, screenx - 1);
        con_putc(' ');
        con_goto(screen_height - 1, screenx - 1);
        p--;
      }
      continue;
    }
    if (c > 31 && c < 127) {
      if (p < linebuf + 80 && screenx < screen_width - 1) {
        *p++ = c;
        con_putc(c);
      }
      continue;
    }
  }
  while (c != 13 && c != 10);
  *p = 0;
  con_scroll(1);
  con_goto(screen_height - 1, 0);
}

static char readchar(void)
{
  line_input(1);
  return *linebuf;
}


static uint8_t ly, lx;

static void begin_upper(void)
{
  ly = screeny;
  lx = screenx;
  flush_word();
  con_goto(0,0);
  upper = 1;
}

char xbuf[] = "<@><@><@><@><@><@><@><@><@><@><@><@><@><@><@><@><@><@><@><@><@><@><@><@><@><@><@>";

static void end_upper(void)
{
  flush_word();
  con_clear_to_eol();
  con_newline();
  upper = 0;
  xbuf[screen_width] = 0;
  con_puts(xbuf);  
  con_goto(ly, lx);
}

#else

#include <stdio.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <sys/wait.h>
#include <termios.h>

#define REDRAW_MASK	REDRAW

static char wbuf[80];
static int wbp = 0;
static int xpos = 0;

static void display_init(void)
{
  char *c;
#ifdef TIOCGWINSZ
  struct winsize w;
  if (ioctl(0, TIOCGWINSZ, &w) != -1) {
    rows = w.ws_row;
    cols = w.ws_col;
    return;
  }
#elif VTSIZE
  int16_t v = ioctl(0, VTSIZE, 0);
  if (v != -1) {
    rows =  v >> 8;
    cols = v;
    return;
  }
#endif
  c = getenv("COLS");
  rows = 25;
  cols = c ? atoi(c): 80;
  if (cols == 0)
    cols = 80;
}

static void display_exit(void)
{
}

static void flush_word(void)
{
  write(1, wbuf, wbp);
  xpos += wbp;
  wbp = 0;
}

static void char_out(char c)
{
  if (c == '\n') {
    flush_word();
    write(1, "\n", 1);
    xpos = 0;
    return;
  }
  if (c != ' ') {
    if (wbp < 80)
      wbuf[wbp++] = c;
    return;
  }
  if (xpos + wbp >= cols) {
    xpos = 0;
    write(1,"\n", 1);
  }
  flush_word();
  write(1," ", 1);
  xpos++;
}

static void strout_lower(const uint8_t *p)
{
  while(*p)
    char_out(*p++);
}

static void strout_lower_spc(const uint8_t *p)
{
  strout_lower(p);
  char_out(' ');
}

static void decout_lower(uint16_t v)
{
#ifdef __linux__
  char buf[9];
  snprintf(buf, 8, "%d", v);	/* FIXME: avoid expensive snprintf */
  strout_lower((uint8_t *)buf);
#else
  strout_lower((uint8_t *)_itoa(v));
#endif
}

static void strout_upper(const uint8_t *p)
{
  strout_lower(p);
}


static void line_input(int m)
{
  int l = read(0, linebuf, sizeof(linebuf));
  if (l < 0)
    error("read");
  linebuf[l] = 0;
  if (l && linebuf[l-1] == '\n')
    linebuf[l-1] = 0;
}

static char readchar(void)
{
  line_input(0);
  return *linebuf;
}

static void begin_upper(void)
{
  strout_upper("\n\n\n\n");
}

static void end_upper(void)
{
  uint8_t l = cols;
  char_out('\n');
  while(l--)
    char_out('-');
  char_out('\n');
}



#endif

/******************** Common code ******************/

static uint8_t yes_or_no(void)
{
  char c;
  do {
    c = readchar();
    if (c == 'Y'  || c == 'y' || c == 'J' || c == 'j')
      return 1;
  } while(c != -1 && c != 'N' && c != 'n');
  return 0;
}

static void exit_game(uint8_t code)
{
  display_exit();
  exit(code);
}

static void error(const char *p)
{
  display_exit();
  write(2, p, strlen(p));
  exit(1);
}

static uint8_t random_chance(uint8_t v)
{
  v = v + v + (v >> 1);	/* scale as 0-249 */
  if (((rand() >> 3) & 0xFF) <= v)
    return 1;
  return 0;
}

static char *skip_spaces(char *p)
{
  while(*p && isspace(*p))
    p++;
  return p;
}

static char *copyword(char *p)
{
  char *t = wordbuf;
  p = skip_spaces(p);
  memset(wordbuf, ' ', WORDSIZE+1);
  while (*p && !isspace(*p) && t < wordbuf + WORDSIZE)
    *t++ = *p++;
  while(*p && !isspace(*p))
    p++;
  return p;
}

static int wordeq(const uint8_t *a, const char *b, uint8_t l)
{
  while(l--)
    if ((*a++ & 0x7F) != toupper(*b++))
      return 0;
  return 1;
}

static uint8_t whichword(const uint8_t *p)
{
  uint8_t code = 0;
  uint8_t i = 0;

  if (*wordbuf == 0 || *wordbuf == ' ')
    return 0;		/* No word */
  i--;
  
  do {
    i++;
    if (!(*p & 0x80))
      code = i;
    if (wordeq(p, wordbuf, WORDSIZE))
      return code;
    p += WORDSIZE;
  } while(*p != 0);
  return 255;
}

static void scan_noun(char *x)
{
  x = skip_spaces(x);
  nounbuf = x;
  copyword(x);
  noun = whichword(nouns);
}

static void scan_input(void)
{
  char *x = copyword(linebuf);
  verb = whichword(verbs);
  scan_noun(x);
}

void abbrevs(void)
{
  char *x = skip_spaces(linebuf);
  const char *p = NULL;
  if (x[1] != 0 && x[1] != ' ')
    return;
  switch(toupper(*x)) {
    case 'N': 
      p = "NORTH";
      break;
    case 'E':
      p = "EAST";
      break;
    case 'S':
      p = "SOUTH";
      break;
    case 'W':
      p = "WEST";
      break;
    case 'U':
      p = "UP";
      break;
    case 'D':
      p = "DOWN";
      break;
    case 'I':
      p = "INVEN";
      break;
  }
  if (p)
    strcpy(linebuf, p);
}
  
static const uint8_t *run_conditions(const uint8_t *p, uint8_t n)
{
  uint8_t i;
  
  for (i = 0; i < n; i++) {
    uint8_t opc = *p++;
    uint16_t par = *p++ | ((opc & 0xE0) >> 5);
    uint8_t op = game.objloc[par];
    opc &= 0x1F;

    switch(opc) {
      case 0:
        *param++ = par;
        break;
      case 1:
        if (op != 255)
          return NULL;
        break;
      case 2:
        if (op != game.location)
          return NULL;
        break;
      case 3:
        if (op != 255 && op != game.location)
          return NULL;
        break;
      case 4:
        if (game.location != par)
          return NULL;
        break;
      case 5:
        if (op == game.location)
          return NULL;
        break;
      case 6:
        if (op == 255)
          return NULL;
        break;
      case 7:
        if (game.location == par)
          return NULL;
        break;
      case 8:
        if (!(game.bitflags & (ONEBIT << par)))
          return NULL;
        break;
      case 9:
        if (game.bitflags & (ONEBIT << par))
          return NULL;
        break;
      case 10:
        if (!game.carried)
          return NULL;
        break;
      case 11:
        if (game.carried)
          return NULL;
        break;
      case 12:
        if (op == 255 || op == game.location)
          return NULL;
        break;
      case 13:
        if (op == 0)
          return NULL;
        break;
      case 14:
        if (op != 0)
          return NULL;
        break;
      case 15:
        if (game.counter > par)
          return NULL;
        break;
      case 16:
        if (game.counter < par)
          return NULL;
        break;
      case 17:
        if (op != objinit[par]) 
          return NULL;
        break;
      case 18:
        if (op == objinit[par])
          return NULL;
        break;
      case 19:
        if (game.counter != par)
          return NULL;
        break;
      default:
        error("BADCOND");
    }
  }
  return p;
}

uint8_t islight(void)
{
  uint8_t l = game.objloc[LIGHT_SOURCE];
  if (!(game.bitflags & (ONEBIT << DARKFLAG)))
    return 1;
  if (l == 255 || l == game.location)
    return 1;
  return 0;
}

static void action_look(void)
{
  const uint8_t *e;
  const uint8_t *p;
  uint8_t c;
  uint8_t f = 1;
  const uint8_t **op = objtext;

  redraw = 0;

  begin_upper();

  if (!islight()) {
    strout_upper(itsdark);
    end_upper();
    return;
  }
  p = locdata[game.location].text;
  e = locdata[game.location].exit;
  if (*p == '*')
    p++;
  else
    strout_upper(youare);
  strout_upper(p);
  strout_upper(newline);
  strout_upper(obexit);

  for (c = 0; c < 6; c++) {
    if (*e++) {
      if (f)
        f = 0;
      else
        strout_upper(dashstr);
      strout_upper(exitmsgptr[c]);
    }
  }
  if (f)
    strout_upper(nonestr);
  strout_upper(dotnewline);
  f = 1;
  e = game.objloc;
  while(e < game.objloc + NUM_OBJ) {
    if (*e++ == game.location) {
      if (f) {
        strout_upper(canalsosee);
        f = 0;
      } else
        strout_upper(dashstr);
      strout_upper(*op);
    }
    op++;
  }
  end_upper();
}

static void action_delay(void)
{
  sleep(2);
}

static void action_dead(void)
{
  strout_lower(dead);
  game.bitflags &= ~(ONEBIT << DARKFLAG);
  game.location = lastloc;
  action_look();
}

static void action_quit(void)
{
  strout_lower(playagain);
  if (yes_or_no())
    longjmp(restart, 0);
  exit_game(0);
}

static void action_score(void)
{
  uint8_t *p = game.objloc;
  const uint8_t **m = objtext;
  uint8_t t = 0, s = 0;

  while(p < game.objloc + NUM_OBJ) {
    if (*m[0] == '*') {
      t++;
      if (*p == treasure)
        s++;
    }
    m++;
    p++;
  }

  strout_lower(stored_msg);
  decout_lower(s);
  strout_lower(stored_msg2);
  decout_lower((s * (uint16_t)100) / t);
  strout_lower(dotnewline);
  if (s == t)
    action_quit();
}

static void action_inventory(void)
{
  uint8_t *p = game.objloc;
  const uint8_t **m = objtext;
  uint8_t f = 1;

  strout_lower(carrying);
  if (game.carried == 0)
    strout_lower(nothing);
  else {  
    while(p < game.objloc + NUM_OBJ) {
      if (*p == 255) {
        if (!f)
          strout_lower(dashstr);
        else
          f = 0;
        strout_lower(*m);
      }
      m++;
      p++;
    }
  }
  strout_lower(dotnewline);
}

static char *filename(void)
{
  strout_lower("File name ? ");
  line_input(1);
  return skip_spaces(linebuf);
}

static void action_save(void)
{
  int fd;
  char *p = filename();
  if (*p == 0)
    return;
  game.magic = GAME_MAGIC;
  fd = open(p, O_WRONLY|O_CREAT|O_TRUNC, 0600);
  if (fd == -1 || write(fd, &game, sizeof(game)) != sizeof(game) || close(fd) == -1)
    strout_lower("Save failed.\n");
  close(fd);	/* Double closing is safe for non error path */
}

static int action_restore(void)
{
  while(1) {
    char *p = filename();
    int fd;

    if (*p == 0)
      return 0;

    fd = open(p, O_RDONLY, 0600);

    if (fd != -1 && read(fd, &game, sizeof(game)) == sizeof(game) && close(fd) != -1 &&
        game.magic == GAME_MAGIC)
      return 1;

    strout_lower("Load failed.\n");
    close(fd);
  }
}
  
static void moveitem(uint8_t i, uint8_t l)
{
  uint8_t *p = game.objloc + i;
  if (*p == game.location)
    redraw |= REDRAW_MAYBE;
  if (l == game.location)
    redraw |= REDRAW;
  *p = l;
}

static void run_actions(const uint8_t *p, uint8_t n)
{
  uint8_t i;

  for (i = 0; i < n; i++) {
    uint8_t a = *p++;
    uint8_t tmp;
    uint16_t tmp16;

    if (a < 50) {
      strout_lower_spc(msgptr[a]);
      continue;
    }
    if (a > 102 ) {
      strout_lower_spc(msgptr[a - 50]);
      continue;
    }
    switch(a) {
      case 51:	/* nop - check */
        break;
      case 52:	/* Get */
        if (game.carried >= maxcar)
          strout_lower(toomuch);
        else
          moveitem(*param++, 255);
        break;
      case 53: /* Drop */
        moveitem(*param++, game.location);
        break;
      case 54: /* Go */
        game.location = *param++;
        redraw |= REDRAW;
        break;
      case 55: /* Destroy */
      case 59: /* ?? */
        moveitem(*param++, 0);
        break;
      case 56:	/* Set dark flag */
        game.bitflags |= (ONEBIT << DARKFLAG);
        break;
      case 57:	/* Clear dark flag */
        game.bitflags &= ~(ONEBIT << DARKFLAG);
        break;
      case 58:	/* Set bit */
        game.bitflags |= (ONEBIT << *param++);
        break;
      /* 59 see 55 */
      case 60:	/* Clear bit */
        game.bitflags &= ~(ONEBIT << *param++);
        break;
      case 61:	/* Dead */
        action_dead();
        break;
      case 64:	/* Look */
      case 76:	/* Also Look ?? */
        action_look();
        break;
      case 62:	/* Place obj, loc */
        tmp = *param++;
        moveitem(tmp, *param++);
        break;
      case 63:	/* Game over */
        action_quit();
      case 65:	/* Score */
        action_score();
        break;
      case 66:	/* Inventory */
        action_inventory();
      case 67:	/* Set bit 0 */
        game.bitflags |= (ONEBIT << 0);
        break;
      case 68:	/* Clear bit 0 */
        game.bitflags &= ~(ONEBIT << 0);
        break;
      case 69:	/* Refill lamp */
        game.lighttime = lightfill;
        game.bitflags &= ~(ONEBIT << LIGHTOUT);
        moveitem(LIGHT_SOURCE, 255);
        break;
      case 70:	/* Wipe lower */
        /* TODO */
        break;
      case 71:	/* Save */
        action_save();
        break;
      case 72:	/* Swap two objects */
        tmp = game.objloc[*param];
        moveitem(*param, game.objloc[param[1]]);
        moveitem(param[1], tmp);
        param += 2;
        break;
      case 73:
        continuation = 1;
        break;
      case 74:	/* Get without weight rule */
        moveitem(*param++, 255);
        break;
      case 75:	/* Put one item by another */
        moveitem(*param, game.objloc[param[1]]);
        param += 2;
        break;
      case 77:	/* Decrement counter */
        if (game.counter >= 0)
          game.counter--;
        break;
      case 78:	/* Display counter */
        decout_lower(game.counter);
        break;
      case 79:	/* Set counter */
        game.counter = *param++;
        break;
      case 80:	/* Swap player and saved room */
        tmp = game.savedroom;
        game.savedroom = game.location;
        game.location = tmp;
        redraw |= REDRAW;
        break;
      case 81:	/* Swap counter and counter n */
        tmp16 = game.counter;
        game.counter = game.counter_array[*param];
        game.counter_array[*param++] = tmp16;
        break;
      case 82:	/* Add to counter */
        game.counter += *param++;
        break;
      case 83:	/* Subtract from counter */
        game.counter -= *param++;
        if (game.counter < 0)
          game.counter = -1;
        break;
      case 84:	/* Print noun, newline */
        strout_lower((uint8_t *)nounbuf);
        /* Fall through */
      case 86:	/* Print newline */
        strout_lower(newline);
        break;
      case 85:	/* Print noun */ 
        strout_lower((uint8_t *)nounbuf);
        break;
      case 87: /* Swap player and saveroom array entry */
        tmp16 = *param++;
        tmp = game.roomsave[tmp16];
        game.roomsave[tmp16] = game.location;
        if (tmp != game.location) {
          game.location = tmp;
          redraw |= REDRAW;
        }
        break;
      case 88:
        action_delay();
        break;
      case 89:
        param++;		/* SAGA etc specials */
        break;
      default:
        error("BADACT");
    }
  }
}

void next_line(void)
{
  uint8_t c = *linestart++;
  if (!(c & 0x80))
    linestart += 2;	/* Skip verb/noun */
  else if (!(c & 0x60))
    linestart++;	/* Skip random value */
  linestart += (c & 3) + 1;	/* Actions 1 - 4 */
  c >>= 1;
  c &= 0x0E;		/* 2 x conditions */
  linestart += c;
}

void run_line(const uint8_t *ptr, uint8_t c, uint8_t a)
{
  memset(param_buf, 0, sizeof(param_buf));
  param = param_buf;
  if (c)
    ptr = run_conditions(ptr, c);
  if (ptr) {
    actmatch = 1;
    param = param_buf;
    run_actions(ptr, a);
  }
  next_line();
}

void run_table(const uint8_t *tp)
{
  continuation = 0;
  linestart = tp;
  while(1) {
    uint8_t hdr;
    uint8_t c, a;
    tp = linestart;
    hdr = *tp++;
    c = (hdr >> 2) & 0x07;
    a = (hdr & 3) + 1;
    
/*    printf("H%02X c = %d a = %d\n", hdr, c, a); */
    if (hdr == 255)
      return;		/* End of table */
    if (hdr & 0x80) {
      if (hdr & 0x40) {	/* Auto 0 */
        if (continuation)
          run_line(tp, c, a);
        else
          next_line();
        continue;
      }
      continuation = 0;
      if (!(hdr & 0x20)) {	/* Auto number */
        if (random_chance(*tp++))
          run_line(tp, c, a);
        else
          next_line();
        continue;
      }
      run_line(tp, c, a);
    } else {
      if (actmatch)
        return;
/*      printf("VN %d %d\n", *tp, tp[1]); */
      linematch = 1;
      continuation = 0;
      if (*tp++ == verb && (*tp == noun || *tp == 0))
        run_line(tp+1, c, a);
      else
        next_line();
    }
  }
}

uint8_t autonoun(uint8_t loc)
{
  const uint8_t *p = automap;
  if (*wordbuf == ' ' || *wordbuf == 0)
    return 255;
  while(*p) {
    if (strncasecmp((const char *)p, wordbuf, WORDSIZE) == 0 && game.objloc[p[WORDSIZE]] == loc)
      return p[WORDSIZE];
    p += WORDSIZE + 1;
  }
  return 255;
}
  
void run_command(void)
{
  uint8_t tmp;
  run_table(actions);
  if (actmatch)
    return;
  if (verb == VERB_GET) {		/* Get */
    if (noun == 0)
      strout_lower(whatstr);
    else if (game.carried >= maxcar)
      strout_lower(toomuch);
    else {
      tmp = autonoun(game.location);
      if (tmp == 255)
        strout_lower(beyondpower);
      else
        moveitem(tmp, 255);
    }
    actmatch = 1;
    return;
  }
  if (verb == VERB_DROP) {		/* Drop */
    if (noun == 0)
      strout_lower(whatstr);
    else {
      tmp = autonoun(255);
      if (tmp == 255)
        strout_lower(beyondpower);
      else
        moveitem(tmp, game.location);
    }
    actmatch = 1;
    return;
  }
}

void process_light(void)
{
  uint8_t l;
  if ((l = game.objloc[LIGHT_SOURCE]) == 0)
    return;
  if (game.lighttime == 255)
    return;
  if (!--game.lighttime) {
    game.bitflags &= ~(ONEBIT << LIGHTOUT);	/* Check clear ! */
    if (l == 255 || l == game.location) {
      strout_lower(lightout);
      redraw |= REDRAW_MAYBE;
      return;
    }
  }
  if (game.lighttime > 25)
    return;
  strout_lower(lightoutin);
  decout_lower(game.lighttime);
  strout_lower(game.lighttime == 1 ? turn : turns);
}

void main_loop(void)
{
  uint8_t first = 1;
  char *p;

  action_look();
  
  while (1) {
    if (!first)
      process_light();
    else
      first = 0;
    verb = 0;
    noun = 0;

    run_table(status);

    if (redraw & REDRAW_MASK)
      action_look();
    strout_lower(whattodo);

    do {
      do {
        strout_lower(prompt);
        line_input(0);
        abbrevs();
        p = skip_spaces(linebuf);
      }
      while(*p == 0);

      scan_noun(p);
      if (noun && noun <= 6) {
        verb = VERB_GO;
        break;
      }
      scan_input();
      if (verb == 255)
        strout_lower(dontknow);
    } while (verb == 255);
    
    if (verb == VERB_GO) {
      if (!noun) {
        strout_lower(givedirn);
        continue;
      }
      if (noun <= 6) {
        uint8_t light = islight();
        uint8_t dir;

        if (!light)
          strout_lower(darkdanger);
        dir = locdata[game.location].exit[noun - 1];
        if (!dir) {
          if (!light) {
            strout_lower(brokeneck);
            action_delay();
            action_dead();
            continue;
          }
          strout_lower(cantgo);
          continue;
        }
        game.location = dir;
        redraw |= REDRAW;
        continue;
      }
    }
    linematch = 0;
    actmatch = 0;
    run_command();
    if (actmatch)
      continue;
    if (linematch) {
      strout_lower(notyet);
      continue;
    }
    strout_lower(dontunderstand);
  }
}

void start_game(void)
{
  memcpy(game.objloc, objinit, sizeof(game.objloc));
  game.bitflags = 0;
  game.counter = 0;
  memset(game.counter_array, 0, sizeof(game.counter_array));
  game.savedroom = 0;
  memset(game.roomsave, 0, sizeof(game.roomsave));
  game.location = startloc;
  game.lighttime = startlamp;
  game.carried = startcarried;
}

int main(int argc, char *argv[])
{
  display_init();
  setjmp(restart);
  strout_lower("Restore a saved game ? ");
  if (!yes_or_no() || !action_restore())
    start_game();
  main_loop();
}

export CROSS_AS=as68
export CROSS_LD= ld68
export CROSS_CC = cc68
export CROSS_CCOPTS= -m6800 -X -c -I$(ROOT_DIR)/cpu-6800 -I$(ROOT_DIR)/platform-$(TARGET) -I$(ROOT_DIR)/include
export CROSS_CC_SEG1=
export CROSS_CC_SEG2=
export CROSS_CC_SEG3=
export CROSS_CC_SEGDISC= --code-name discard --rodata-name discard
export CROSS_CC_VIDEO=
export CROSS_CC_FONT=
export CROSS_CC_NETWORK=
export ASOPTS=
export ASMEXT = .s
export BINEXT = .o
export BITS=16
export EXECFORMAT=16

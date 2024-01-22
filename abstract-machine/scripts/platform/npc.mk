AM_SRCS := riscv/npc/start.S \
           riscv/npc/trm.c \
           riscv/npc/ioe.c \
           riscv/npc/timer.c \
           riscv/npc/input.c \
           riscv/npc/cte.c \
           riscv/npc/trap.S \
           platform/dummy/vme.c \
           platform/dummy/mpe.c

BUILD_DIR = $(shell dirname $(IMAGE).elf)
CFLAGS    += -fdata-sections -ffunction-sections
LDFLAGS   += -T $(AM_HOME)/scripts/linker.ld \
						 --defsym=_pmem_start=0x80000000 --defsym=_entry_offset=0x0
LDFLAGS   += --gc-sections -e _start
CFLAGS += -DMAINARGS=\"$(mainargs)\"

ifdef CONFIG_DIFFTEST
GUEST_ISA = riscv32
CONFIG_DIFFTEST_REF_NAME = nemu-interpreter
DIFF_REF_PATH = $(NEMU_HOME)
DIFF_REF_SO = $(DIFF_REF_PATH)/build/$(GUEST_ISA)-$(CONFIG_DIFFTEST_REF_NAME)-so
# MKFLAGS = GUEST_ISA=$(GUEST_ISA) SHARE=1 ENGINE=interpreter
ARGS_DIFF = --diff=$(DIFF_REF_SO)

# ifndef CONFIG_DIFFTEST_REF_NEMU
# $(DIFF_REF_SO):
# 	$(MAKE) -s -C $(DIFF_REF_PATH) $(MKFLAGS)
# endif
endif

NPCFLAGS += --log=$(shell dirname $(IMAGE).elf)/npc-log.txt
NPCFLAGS += $(ARGS_DIFF)
NPCFLAGS += --ftrace=$(shell dirname $(IMAGE).elf)/$(ALL)-$(ARCH).elf



.PHONY: $(AM_HOME)/am/src/riscv/npc/trm.c $(DIFF_REF_SO)

image: $(IMAGE).elf
	@$(OBJDUMP) -d $(IMAGE).elf > $(IMAGE).txt
	@echo + OBJCOPY "->" $(IMAGE_REL).bin
	@$(OBJCOPY) -S --set-section-flags .bss=alloc,contents -O binary $(IMAGE).elf $(IMAGE).bin

gdb: image
	$(MAKE) -C $(NPC_HOME) ISA=$(ISA) gdb ARGS="$(NPCFLAGS)" IMG=$(IMAGE).bin  BUILD_DIR="$(BUILD_DIR)"

run: image
	$(info ARGS_DIFF:$(ARGS_DIFF))
	$(MAKE) -C $(NPC_HOME) ISA=$(ISA) run ARGS="$(NPCFLAGS)" IMG=$(IMAGE).bin  BUILD_DIR="$(BUILD_DIR)"

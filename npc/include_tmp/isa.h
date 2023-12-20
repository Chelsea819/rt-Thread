/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#ifndef __ISA_H__
#define __ISA_H__

// Located at src/isa/$(GUEST_ISA)/include/isa-def.h
#include "isa-def.h"

// The macro `__GUEST_ISA__` is defined in $(CFLAGS).
// It will be expanded as "x86" or "mips32" ...
typedef concat(__GUEST_ISA__, _CPU_state) CPU_state;  //寄存器结构体
typedef concat(__GUEST_ISA__, _ISADecodeInfo) ISADecodeInfo;

// exec
struct Decode;
// int isa_exec_once(struct Decode *s);

// // memory
// enum { MMU_DIRECT, MMU_TRANSLATE, MMU_FAIL };
// enum { MEM_TYPE_IFETCH, MEM_TYPE_READ, MEM_TYPE_WRITE };
// enum { MEM_RET_OK, MEM_RET_FAIL, MEM_RET_CROSS_PAGE };
// #ifndef isa_mmu_check
// /*检查当前系统状态下对内存区间为[vaddr, vaddr + len), 
// 类型为type的访问是否需要经过地址转换*/
// int isa_mmu_check(vaddr_t vaddr, int len, int type);
// #endif
// paddr_t isa_mmu_translate(vaddr_t vaddr, int len, int type);

// // interrupt/exception
// vaddr_t isa_raise_intr(word_t NO, vaddr_t epc);
// #define INTR_EMPTY ((word_t)-1)
// word_t isa_query_intr();

// // difftest
// bool isa_difftest_checkregs(CPU_state *ref_r, vaddr_t pc);
// void isa_difftest_attach();

#endif

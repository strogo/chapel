/*
 * Copyright 2004-2016 Cray Inc.
 * Other additional copyright holders may be indicated within.
 * 
 * The entirety of this work is licensed under the Apache License,
 * Version 2.0 (the "License"); you may not use this file except
 * in compliance with the License.
 * 
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


// NOTE: there is no include guard. This is so that the mem-warning and
// mem-no-warning headers can be included an arbitrary number of times to
// disable and then re-enable the macros


// this function gets its own ifdef so that it's not redefined
#ifndef _chpl_mem_warning_macros_really_h_
#define _chpl_mem_warning_macros_really_h_
// MPF - I needed to call the system free to pair with system valloc
// (these are for I/O buffers that don't belong on the Chapel sharable
// heap anyway because they could be mmap'd - and then are only
// sharable when everything is sharable)
static inline void sys_free(void *ptr) { free(ptr); }
#endif

#define malloc(size)       dont_use_malloc_use_chpl_mem_allocMany_instead
#define calloc(num, size)  dont_use_calloc_use_chpl_mem_allocMany_instead
#define free(ptr)          dont_use_free_use_chpl_mem_free_instead
#define realloc(ptr, size) dont_use_realloc_use_chpl_mem_realloc_instead

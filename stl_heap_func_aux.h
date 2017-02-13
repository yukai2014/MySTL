/*
 * Copyright [2012-2015] yukai
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * /test_sgiSTL/src/stl_heap_func_aux.h
 *
 *  Created on: Feb 12, 2017
 *      Author: yukai
 *		   Email: yukai2014@gmail.com
 *
 * Description:
 *
 */

#ifndef STL_HEAP_FUNC_AUX_H_
#define STL_HEAP_FUNC_AUX_H_

#include "./stl_heap.h"
#include "./stl_light_heap.h"

struct default_heap_func {
 public:
  //  typedef make_heap my_make_heap;
  //  using ::make_heap;
  //  using ::sort_heap;
  //  using ::push_heap;
  //  using ::pop_heap;
  template <typename... Args>
  auto make_heap(Args&&... args)
      -> decltype(::make_heap(std::forward<Args>(args)...)) {
    return ::make_heap(std::forward<Args>(args)...);
  }
  template <typename... Args>
  auto sort_heap(Args&&... args)
      -> decltype(::sort_heap(std::forward<Args>(args)...)) {
    return ::sort_heap(std::forward<Args>(args)...);
  }
  template <typename... Args>
  auto push_heap(Args&&... args)
      -> decltype(::push_heap(std::forward<Args>(args)...)) {
    return ::push_heap(std::forward<Args>(args)...);
  }
  template <typename... Args>
  auto pop_heap(Args&&... args)
      -> decltype(::pop_heap(std::forward<Args>(args)...)) {
    return ::pop_heap(std::forward<Args>(args)...);
  }
};

using light_heap_func = light_heap;

#endif  // STL_HEAP_FUNC_AUX_H_

/*
 * Copyright [2012-2015] DaSE@ECNU
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
 * time_getter.h
 *
 *  Created on: Sep 3, 2015
 *      Author: yukai
 *		 Email: yukai2014@gmail.com
 * 
 * Description:
 *
 */

#ifndef program_TIMER_H_
#define program_TIMER_H_
#include <sys/time.h>

/***
 * @brief
 */
class Timer {
 public:
  static inline double GetCurrentMs() {
    timeval t_start;
    gettimeofday(&t_start, NULL);
    return t_start.tv_sec * 1000 + 1.0 * t_start.tv_usec / 1000;
  }

  /*
   * @param start: the start time
   * @return : the elapsed time(ms) from start, accurate to us
   */
  static inline double GetElapsedTime(double start) {
    timeval t_end;
    gettimeofday(&t_end, NULL);
    return (t_end.tv_sec * 1000 + 1.0 * t_end.tv_usec / 1000) - start;
  }
 private:
};


#endif /* program_TIMER_H_ */

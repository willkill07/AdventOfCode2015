# Advent of Code - 2015

All implementations are written in C++, strictly adhering to C++11/14 guidelines.

## Compiling

* Invoke `make all` to compile all the days
* Invoke `make runall` to execute all the days
* To compile a specific day, invoke `make dayXX` where `XX` is the number of the day (zero padding required)
* To run a specific day, invoke `make run_dayXX`

## Metrics

* Lines: Number of lines given by `wc`
* Code: `Lines` - `(# preprocessor lines)` - `(lines with no alphanumeric chars)`
* Bytes: Number of total characters
* Chars: Number of non-whitespace characters
* Time: Time in seconds to execute each part independently (separate runs)
* Source: link to implementation
* Headers: C++ includes used for solution

## Leaderboard Highlights:

* Day 5: Placed #60
* Day 8: Placed #14
* Day 10: Placed #64
* Day 17: Placed #68

## Detailed Information

 Day | Lines | Code | Bytes | Chars | Time | Source | Headers
:---:|:-----:|:----:|:-----:|:-----:| ----:|:------:|:-------
01|12|7|325|249|0.0031|[day01.cpp](https://github.com/willkill07/adventofcode/blob/master/src/day01/day01.cpp)|`iostream` [`timer.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/timer.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/io.hpp)
02|22|12|624|490|0.0053|[day02.cpp](https://github.com/willkill07/adventofcode/blob/master/src/day02/day02.cpp)|`algorithm` `iostream` `regex` `string` [`timer.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/timer.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/io.hpp)
03|29|17|647|493|0.0078|[day03.cpp](https://github.com/willkill07/adventofcode/blob/master/src/day03/day03.cpp)|`iostream` `map` `tuple` [`timer.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/timer.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/io.hpp)
04|15|8|504|406|0.5687|[day04.cpp](https://github.com/willkill07/adventofcode/blob/master/src/day04/day04.cpp)|`iostream` `string` `md5.hpp` [`timer.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/timer.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/io.hpp)
05|17|8|630|517|0.0601|[day05.cpp](https://github.com/willkill07/adventofcode/blob/master/src/day05/day05.cpp)|`iostream` `regex` `string` [`timer.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/timer.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/io.hpp)
06|26|15|930|709|0.0200|[day06.cpp](https://github.com/willkill07/adventofcode/blob/master/src/day06/day06.cpp)|`iostream` `regex` `valarray` [`timer.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/timer.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/io.hpp)
07|66|44|2056|1510|0.0060|[day07.cpp](https://github.com/willkill07/adventofcode/blob/master/src/day07/day07.cpp)|`iostream` `map` `regex` `string` [`timer.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/timer.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/io.hpp)
08|27|13|753|586|0.0060|[day08.cpp](https://github.com/willkill07/adventofcode/blob/master/src/day08/day08.cpp)|`iostream` `iterator` `numeric` `regex` `string` [`timer.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/timer.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/io.hpp)
09|38|21|1217|973|0.0125|[day09.cpp](https://github.com/willkill07/adventofcode/blob/master/src/day09/day09.cpp)|`iostream` `limits` `numeric` `regex` `set` `string` `unordered_map` `vector` [`timer.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/timer.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/io.hpp)
10|22|12|664|508|0.0586|[day10.cpp](https://github.com/willkill07/adventofcode/blob/master/src/day10/day10.cpp)|`algorithm` `iostream` `iterator` `vector` [`timer.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/timer.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/io.hpp)
11|40|26|923|644|0.0190|[day11.cpp](https://github.com/willkill07/adventofcode/blob/master/src/day11/day11.cpp)|`iostream` `string` [`timer.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/timer.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/io.hpp)
12|37|27|1061|724|0.0311|[day12.cpp](https://github.com/willkill07/adventofcode/blob/master/src/day12/day12.cpp)|`iostream` `stack` `string` [`timer.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/timer.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/io.hpp)
13|36|21|1264|1009|0.0148|[day13.cpp](https://github.com/willkill07/adventofcode/blob/master/src/day13/day13.cpp)|`iostream` `limits` `numeric` `regex` `set` `string` `unordered_map` `vector` [`timer.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/timer.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/io.hpp)
14|53|32|1602|1187|0.0008|[day14.cpp](https://github.com/willkill07/adventofcode/blob/master/src/day14/day14.cpp)|`algorithm` `iostream` `regex` `string` `vector` [`timer.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/timer.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/io.hpp)
15|53|33|1743|1371|0.0079|[day15.cpp](https://github.com/willkill07/adventofcode/blob/master/src/day15/day15.cpp)|`iostream` `numeric` `regex` `valarray` `vector` [`timer.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/timer.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/io.hpp)
16|31|16|1274|1080|0.0047|[day16.cpp](https://github.com/willkill07/adventofcode/blob/master/src/day16/day16.cpp)|`functional` `iostream` `numeric` `regex` `unordered_map` [`timer.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/timer.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/io.hpp)
17|38|22|1093|857|0.0002|[day17.cpp](https://github.com/willkill07/adventofcode/blob/master/src/day17/day17.cpp)|`algorithm` `iostream` `iterator` `numeric` `vector` `utility` [`timer.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/timer.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/io.hpp)
**TOTAL**|**562**|**334**|**17310**|**13313**|**0.8266**| | `iostream`&nbsp;<sup>**`17`**</sup> [`timer.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/timer.hpp)&nbsp;<sup>**`17`**</sup> [`io.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/io.hpp)&nbsp;<sup>**`17`**</sup> `string`&nbsp;<sup>**`10`**</sup> `regex`&nbsp;<sup>**`10`**</sup> `vector`&nbsp;<sup>**`6`**</sup> `numeric`&nbsp;<sup>**`6`**</sup> `algorithm`&nbsp;<sup>**`4`**</sup> `iterator`&nbsp;<sup>**`3`**</sup> `unordered_map`&nbsp;<sup>**`3`**</sup> `valarray`&nbsp;<sup>**`2`**</sup> `limits`&nbsp;<sup>**`2`**</sup> `map`&nbsp;<sup>**`2`**</sup> `set`&nbsp;<sup>**`2`**</sup> `tuple`&nbsp;<sup>**`1`**</sup> `md5.hpp`&nbsp;<sup>**`1`**</sup> `stack`&nbsp;<sup>**`1`**</sup> `utility`&nbsp;<sup>**`1`**</sup> `functional`&nbsp;<sup>**`1`**</sup>

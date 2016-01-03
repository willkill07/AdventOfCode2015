# Advent of Code - 2015

All implementations are written in C++, strictly adhering to C++11/14 guidelines.

## Compiling

* Invoke `make` to compile all the days
* Invoke `./advent` to execute all the days
* To run a specific day, invoke `./advent -f <dayXX>`
* To run a specific part, invoke `./advent -p <1,2>`
* To see more detailed help, consult `./advent --help`

## Metrics

* Lines: Number of lines given by `wc`
* Code: `Lines` - `(# preprocessor lines)` - `(lines with no alphanumeric chars)`
* Bytes: Number of total characters
* Chars: Number of non-whitespace characters
* Time: Time in milliseconds to execute each part independently (separate runs)
* Source: link to implementation
* Headers: C++ includes used for solution

## Leaderboard Highlights:

* Day 5: Placed #60
* Day 8: Placed #14
* Day 10: Placed #64
* Day 17: Placed #68
* Day 20: Placed #33
* Day 23: Placed #83
* Day 24: Placed #62

## Detailed Information

 Day | Lines | Code | Bytes | Chars | Time (ms) | Source | Headers
:---:|:-----:|:----:|:-----:|:-----:| ---------:|:------:|:-------
01|8|5|263|203|`0.2741`|[day01.cpp](https://github.com/willkill07/adventofcode/blob/cplusplus/src/day01.cpp)|[`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/Solution.hpp)
02|16|10|545|429|`5.7160`|[day02.cpp](https://github.com/willkill07/adventofcode/blob/cplusplus/src/day02.cpp)|`algorithm` [`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/Solution.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/io.hpp)
03|25|15|597|461|`2.0514`|[day03.cpp](https://github.com/willkill07/adventofcode/blob/cplusplus/src/day03.cpp)|`map` `tuple` [`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/Solution.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/io.hpp)
04|16|9|570|464|`268.3305`|[day04.cpp](https://github.com/willkill07/adventofcode/blob/cplusplus/src/day04.cpp)|[`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/Solution.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/io.hpp) `md5.hpp`
05|10|6|545|454|`56.6936`|[day05.cpp](https://github.com/willkill07/adventofcode/blob/cplusplus/src/day05.cpp)|[`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/Solution.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/io.hpp)
06|21|13|869|664|`14.6189`|[day06.cpp](https://github.com/willkill07/adventofcode/blob/cplusplus/src/day06.cpp)|`valarray` [`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/Solution.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/io.hpp)
07|61|42|1997|1467|`5.2393`|[day07.cpp](https://github.com/willkill07/adventofcode/blob/cplusplus/src/day07.cpp)|`unordered_map` [`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/Solution.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/io.hpp)
08|22|11|676|525|`3.8572`|[day08.cpp](https://github.com/willkill07/adventofcode/blob/cplusplus/src/day08.cpp)|`iterator` `numeric` [`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/Solution.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/io.hpp)
09|32|18|1134|909|`17.1256`|[day09.cpp](https://github.com/willkill07/adventofcode/blob/cplusplus/src/day09.cpp)|`limits` `numeric` `set` `unordered_map` `vector` [`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/Solution.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/io.hpp) [`util.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/util.hpp)
10|19|10|620|478|`59.0254`|[day10.cpp](https://github.com/willkill07/adventofcode/blob/cplusplus/src/day10.cpp)|`algorithm` `iterator` `vector` [`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/Solution.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/io.hpp)
11|36|24|847|585|`19.3216`|[day11.cpp](https://github.com/willkill07/adventofcode/blob/cplusplus/src/day11.cpp)|[`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/Solution.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/io.hpp)
12|34|26|1006|682|`2.3461`|[day12.cpp](https://github.com/willkill07/adventofcode/blob/cplusplus/src/day12.cpp)|`stack` [`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/Solution.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/io.hpp)
13|30|18|1181|945|`12.9566`|[day13.cpp](https://github.com/willkill07/adventofcode/blob/cplusplus/src/day13.cpp)|`limits` `numeric` `set` `unordered_map` `vector` [`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/Solution.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/io.hpp) [`util.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/util.hpp)
14|46|30|1533|1126|`0.5783`|[day14.cpp](https://github.com/willkill07/adventofcode/blob/cplusplus/src/day14.cpp)|`algorithm` `vector` [`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/Solution.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/io.hpp)
15|48|31|1683|1326|`7.8162`|[day15.cpp](https://github.com/willkill07/adventofcode/blob/cplusplus/src/day15.cpp)|`numeric` `valarray` `vector` [`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/Solution.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/io.hpp)
16|26|13|1235|1057|`4.0786`|[day16.cpp](https://github.com/willkill07/adventofcode/blob/cplusplus/src/day16.cpp)|`functional` `numeric` `unordered_map` [`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/Solution.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/io.hpp) [`util.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/util.hpp)
17|26|18|873|667|`0.0376`|[day17.cpp](https://github.com/willkill07/adventofcode/blob/cplusplus/src/day17.cpp)|`algorithm` `array` `limits` `vector` [`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/Solution.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/io.hpp)
18|36|23|1291|996|`2.8806`|[day18.cpp](https://github.com/willkill07/adventofcode/blob/cplusplus/src/day18.cpp)|`array` [`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/Solution.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/io.hpp)
19|28|22|1056|821|`0.9759`|[day19.cpp](https://github.com/willkill07/adventofcode/blob/cplusplus/src/day19.cpp)|`unordered_map` `unordered_set` [`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/Solution.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/io.hpp)
20|14|9|493|381|`33.4401`|[day20.cpp](https://github.com/willkill07/adventofcode/blob/cplusplus/src/day20.cpp)|`array` [`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/Solution.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/io.hpp)
21|29|21|1264|983|`0.0653`|[day21.cpp](https://github.com/willkill07/adventofcode/blob/cplusplus/src/day21.cpp)|`array` `cmath` [`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/Solution.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/io.hpp)
22|73|50|2224|1665|`2.8077`|[day22.cpp](https://github.com/willkill07/adventofcode/blob/cplusplus/src/day22.cpp)|`limits` `unordered_set` [`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/Solution.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/io.hpp)
23|30|20|1295|1015|`0.3027`|[day23.cpp](https://github.com/willkill07/adventofcode/blob/cplusplus/src/day23.cpp)|`algorithm` `vector` [`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/Solution.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/io.hpp) [`util.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/util.hpp)
24|31|19|950|738|`7.4216`|[day24.cpp](https://github.com/willkill07/adventofcode/blob/cplusplus/src/day24.cpp)|`algorithm` `numeric` `vector` [`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/Solution.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/io.hpp) [`util.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/util.hpp)
25|23|15|705|523|`0.0437`|[day25.cpp](https://github.com/willkill07/adventofcode/blob/cplusplus/src/day25.cpp)|[`io.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/io.hpp) [`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/Solution.hpp)
**TOTAL**|**740**|**478**|**25452**|**19564**|**528.005**| |`  Solution.hpp`&nbsp;<sup>**`25`**</sup> ` io.hpp`&nbsp;<sup>**`24`**</sup> ` vector`&nbsp;<sup>**`8`**</sup> ` algorithm`&nbsp;<sup>**`6`**</sup> ` numeric`&nbsp;<sup>**`6`**</sup> ` unordered_map`&nbsp;<sup>**`5`**</sup> ` util.hpp`&nbsp;<sup>**`5`**</sup> ` limits`&nbsp;<sup>**`4`**</sup> ` array`&nbsp;<sup>**`4`**</sup> ` set`&nbsp;<sup>**`2`**</sup> ` valarray`&nbsp;<sup>**`2`**</sup> ` iterator`&nbsp;<sup>**`2`**</sup> ` unordered_set`&nbsp;<sup>**`2`**</sup> ` stack`&nbsp;<sup>**`1`**</sup> ` functional`&nbsp;<sup>**`1`**</sup> ` cmath`&nbsp;<sup>**`1`**</sup> ` tuple`&nbsp;<sup>**`1`**</sup> ` md5.hpp`&nbsp;<sup>**`1`**</sup> ` map`&nbsp;<sup>**`1`**</sup> ` `

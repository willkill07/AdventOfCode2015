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
* Day 20: Placed #33
* Day 23: Placed #83
* Day 24: Placed #62

## Detailed Information

 Day | Lines | Code | Bytes | Chars | Time | Source | Headers
:---:|:-----:|:----:|:-----:|:-----:| ----:|:------:|:-------
01|10|6|286|219|.00026583|[day01.cpp](https://github.com/willkill07/adventofcode/blob/cplusplus/src/day01.cpp)|[`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/Solution.hpp)
02|18|11|568|445|.00457593|[day02.cpp](https://github.com/willkill07/adventofcode/blob/cplusplus/src/day02.cpp)|`algorithm` [`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/Solution.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/io.hpp)
03|27|16|612|477|.00197877|[day03.cpp](https://github.com/willkill07/adventofcode/blob/cplusplus/src/day03.cpp)|`map` `tuple` [`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/Solution.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/io.hpp)
04|18|10|593|480|.27511161|[day04.cpp](https://github.com/willkill07/adventofcode/blob/cplusplus/src/day04.cpp)|[`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/Solution.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/io.hpp) `md5.hpp`
05|13|7|574|472|.05238096|[day05.cpp](https://github.com/willkill07/adventofcode/blob/cplusplus/src/day05.cpp)|[`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/Solution.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/io.hpp)
06|23|14|892|680|.01597485|[day06.cpp](https://github.com/willkill07/adventofcode/blob/cplusplus/src/day06.cpp)|`valarray` [`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/Solution.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/io.hpp)
07|63|43|2020|1483|.00502698|[day07.cpp](https://github.com/willkill07/adventofcode/blob/cplusplus/src/day07.cpp)|`unordered_map` [`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/Solution.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/io.hpp)
08|24|12|699|541|.00391676|[day08.cpp](https://github.com/willkill07/adventofcode/blob/cplusplus/src/day08.cpp)|`iterator` `numeric` [`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/Solution.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/io.hpp)
09|34|19|1157|925|.01351541|[day09.cpp](https://github.com/willkill07/adventofcode/blob/cplusplus/src/day09.cpp)|`limits` `numeric` `set` `unordered_map` `vector` [`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/Solution.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/io.hpp) [`util.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/util.hpp)
10|21|11|643|494|.05971071|[day10.cpp](https://github.com/willkill07/adventofcode/blob/cplusplus/src/day10.cpp)|`algorithm` `iterator` `vector` [`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/Solution.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/io.hpp)
11|38|25|870|601|.01638214|[day11.cpp](https://github.com/willkill07/adventofcode/blob/cplusplus/src/day11.cpp)|[`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/Solution.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/io.hpp)
12|36|27|1029|698|.00233977|[day12.cpp](https://github.com/willkill07/adventofcode/blob/cplusplus/src/day12.cpp)|`stack` [`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/Solution.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/io.hpp)
13|32|19|1204|961|.01337966|[day13.cpp](https://github.com/willkill07/adventofcode/blob/cplusplus/src/day13.cpp)|`limits` `numeric` `set` `unordered_map` `vector` [`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/Solution.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/io.hpp) [`util.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/util.hpp)
14|48|31|1556|1142|.00089997|[day14.cpp](https://github.com/willkill07/adventofcode/blob/cplusplus/src/day14.cpp)|`algorithm` `vector` [`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/Solution.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/io.hpp)
15|50|32|1706|1342|.01020813|[day15.cpp](https://github.com/willkill07/adventofcode/blob/cplusplus/src/day15.cpp)|`numeric` `valarray` `vector` [`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/Solution.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/io.hpp)
16|28|14|1258|1073|.00423421|[day16.cpp](https://github.com/willkill07/adventofcode/blob/cplusplus/src/day16.cpp)|`functional` `numeric` `unordered_map` [`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/Solution.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/io.hpp) [`util.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/util.hpp)
17|28|19|896|683|.00005710|[day17.cpp](https://github.com/willkill07/adventofcode/blob/cplusplus/src/day17.cpp)|`algorithm` `array` `limits` `vector` [`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/Solution.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/io.hpp)
18|38|24|1314|1012|.00229477|[day18.cpp](https://github.com/willkill07/adventofcode/blob/cplusplus/src/day18.cpp)|`array` [`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/Solution.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/io.hpp)
19|30|23|1079|837|.00105040|[day19.cpp](https://github.com/willkill07/adventofcode/blob/cplusplus/src/day19.cpp)|`unordered_map` `unordered_set` [`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/Solution.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/io.hpp)
20|16|10|516|397|.03042898|[day20.cpp](https://github.com/willkill07/adventofcode/blob/cplusplus/src/day20.cpp)|`array` [`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/Solution.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/io.hpp)
21|31|22|1287|999|.00006910|[day21.cpp](https://github.com/willkill07/adventofcode/blob/cplusplus/src/day21.cpp)|`array` `cmath` [`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/Solution.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/io.hpp)
22|75|51|2247|1681|.00299247|[day22.cpp](https://github.com/willkill07/adventofcode/blob/cplusplus/src/day22.cpp)|`limits` `unordered_set` [`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/Solution.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/io.hpp)
23|32|21|1318|1031|.00032525|[day23.cpp](https://github.com/willkill07/adventofcode/blob/cplusplus/src/day23.cpp)|`algorithm` `vector` [`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/Solution.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/io.hpp) [`util.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/util.hpp)
24|33|20|973|754|.00682565|[day24.cpp](https://github.com/willkill07/adventofcode/blob/cplusplus/src/day24.cpp)|`algorithm` `numeric` `vector` [`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/Solution.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/io.hpp) [`util.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/util.hpp)
25|25|16|728|539|.00004402|[day25.cpp](https://github.com/willkill07/adventofcode/blob/cplusplus/src/day25.cpp)|[`io.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/io.hpp) [`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/Solution.hpp)
**TOTAL**|**791**|**503**|**26025**|**19966**|**0.523989**| | [`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/Solution.hpp)&nbsp;<sup>**`25`**</sup> [`io.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/io.hpp)&nbsp;<sup>**`24`**</sup> `vector`&nbsp;<sup>**`8`**</sup> `algorithm`&nbsp;<sup>**`6`**</sup> `numeric`&nbsp;<sup>**`6`**</sup> [`util.hpp`](https://github.com/willkill07/adventofcode/blob/cplusplus/util/include/util.hpp)&nbsp;<sup>**`5`**</sup> `unordered_map`&nbsp;<sup>**`5`**</sup> `limits`&nbsp;<sup>**`4`**</sup> `array`&nbsp;<sup>**`4`**</sup> `valarray`&nbsp;<sup>**`2`**</sup> `unordered_set`&nbsp;<sup>**`2`**</sup> `set`&nbsp;<sup>**`2`**</sup> `iterator`&nbsp;<sup>**`2`**</sup> `functional`&nbsp;<sup>**`1`**</sup> `tuple`&nbsp;<sup>**`1`**</sup> `stack`&nbsp;<sup>**`1`**</sup> `cmath`&nbsp;<sup>**`1`**</sup> `md5.hpp`&nbsp;<sup>**`1`**</sup> `map`&nbsp;<sup>**`1`**</sup>

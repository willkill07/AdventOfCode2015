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
01|8|5|275|212|`0.2673`|[Day01.cpp](https://github.com/willkill07/adventofcode/blob/master/src/Day01.cpp)|[`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/Solution.hpp)
02|16|10|564|445|`4.7199`|[Day02.cpp](https://github.com/willkill07/adventofcode/blob/master/src/Day02.cpp)|`algorithm` [`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/Solution.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/io.hpp)
03|25|15|609|470|`1.7293`|[Day03.cpp](https://github.com/willkill07/adventofcode/blob/master/src/Day03.cpp)|`map` `tuple` [`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/Solution.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/io.hpp)
04|16|9|582|473|`278.2099`|[Day04.cpp](https://github.com/willkill07/adventofcode/blob/master/src/Day04.cpp)|[`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/Solution.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/io.hpp) `md5.hpp`
05|45|31|1383|1038|`0.4139`|[Day05.cpp](https://github.com/willkill07/adventofcode/blob/master/src/Day05.cpp)|`array` `climits` [`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/Solution.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/io.hpp)
06|25|17|947|716|`15.4694`|[Day06.cpp](https://github.com/willkill07/adventofcode/blob/master/src/Day06.cpp)|`array` [`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/Solution.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/io.hpp)
07|61|42|2015|1481|`6.3240`|[Day07.cpp](https://github.com/willkill07/adventofcode/blob/master/src/Day07.cpp)|`unordered_map` [`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/Solution.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/io.hpp)
08|18|12|537|406|`4.5777`|[Day08.cpp](https://github.com/willkill07/adventofcode/blob/master/src/Day08.cpp)|[`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/Solution.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/io.hpp)
09|38|26|1314|1036|`11.6733`|[Day09.cpp](https://github.com/willkill07/adventofcode/blob/master/src/Day09.cpp)|`limits` `set` `unordered_map` `vector` [`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/Solution.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/io.hpp)
10|20|12|565|413|`53.1665`|[Day10.cpp](https://github.com/willkill07/adventofcode/blob/master/src/Day10.cpp)|`vector` [`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/Solution.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/io.hpp)
11|35|23|901|639|`19.2838`|[Day11.cpp](https://github.com/willkill07/adventofcode/blob/master/src/Day11.cpp)|[`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/Solution.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/io.hpp)
12|34|26|1019|690|`0.7171`|[Day12.cpp](https://github.com/willkill07/adventofcode/blob/master/src/Day12.cpp)|`stack` [`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/Solution.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/io.hpp)
13|36|25|1326|1049|`12.7206`|[Day13.cpp](https://github.com/willkill07/adventofcode/blob/master/src/Day13.cpp)|`limits` `set` `unordered_map` `vector` [`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/Solution.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/io.hpp)
14|46|30|1535|1129|`0.5527`|[Day14.cpp](https://github.com/willkill07/adventofcode/blob/master/src/Day14.cpp)|`algorithm` `vector` [`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/Solution.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/io.hpp)
15|48|31|1670|1312|`7.6846`|[Day15.cpp](https://github.com/willkill07/adventofcode/blob/master/src/Day15.cpp)|`numeric` `valarray` `vector` [`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/Solution.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/io.hpp)
16|32|18|1282|1040|`5.2561`|[Day16.cpp](https://github.com/willkill07/adventofcode/blob/master/src/Day16.cpp)|`functional` `unordered_map` [`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/Solution.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/io.hpp) [`util.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/util.hpp)
17|26|18|885|676|`0.0380`|[Day17.cpp](https://github.com/willkill07/adventofcode/blob/master/src/Day17.cpp)|`algorithm` `array` `limits` `vector` [`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/Solution.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/io.hpp)
18|36|23|1306|1009|`2.9326`|[Day18.cpp](https://github.com/willkill07/adventofcode/blob/master/src/Day18.cpp)|`array` [`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/Solution.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/io.hpp)
19|28|22|1056|823|`0.9961`|[Day19.cpp](https://github.com/willkill07/adventofcode/blob/master/src/Day19.cpp)|`unordered_map` `unordered_set` [`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/Solution.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/io.hpp)
20|16|9|512|380|`33.3028`|[Day20.cpp](https://github.com/willkill07/adventofcode/blob/master/src/Day20.cpp)|`array` [`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/Solution.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/io.hpp)
21|28|20|1342|1005|`0.0822`|[Day21.cpp](https://github.com/willkill07/adventofcode/blob/master/src/Day21.cpp)|`array` `cmath` [`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/Solution.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/io.hpp)
22|72|49|2246|1675|`2.8873`|[Day22.cpp](https://github.com/willkill07/adventofcode/blob/master/src/Day22.cpp)|`limits` `unordered_set` [`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/Solution.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/io.hpp)
23|30|20|1304|1020|`0.2965`|[Day23.cpp](https://github.com/willkill07/adventofcode/blob/master/src/Day23.cpp)|`algorithm` `vector` [`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/Solution.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/io.hpp) [`util.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/util.hpp)
24|31|19|961|747|`6.3640`|[Day24.cpp](https://github.com/willkill07/adventofcode/blob/master/src/Day24.cpp)|`algorithm` `numeric` `vector` [`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/Solution.hpp) [`io.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/io.hpp) [`util.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/util.hpp)
25|24|16|733|536|`0.0512`|[Day25.cpp](https://github.com/willkill07/adventofcode/blob/master/src/Day25.cpp)|[`io.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/io.hpp) [`Solution.hpp`](https://github.com/willkill07/adventofcode/blob/master/util/include/Solution.hpp)
**TOTAL**|**794**|**528**|**26869**|**20420**|**469.717**| |`  Solution.hpp`&nbsp;<sup>**`25`**</sup> ` io.hpp`&nbsp;<sup>**`24`**</sup> ` vector`&nbsp;<sup>**`8`**</sup> ` array`&nbsp;<sup>**`6`**</sup> ` algorithm`&nbsp;<sup>**`5`**</sup> ` unordered_map`&nbsp;<sup>**`5`**</sup> ` limits`&nbsp;<sup>**`4`**</sup> ` util.hpp`&nbsp;<sup>**`3`**</sup> ` set`&nbsp;<sup>**`2`**</sup> ` numeric`&nbsp;<sup>**`2`**</sup> ` unordered_set`&nbsp;<sup>**`2`**</sup> ` map`&nbsp;<sup>**`1`**</sup> ` stack`&nbsp;<sup>**`1`**</sup> ` tuple`&nbsp;<sup>**`1`**</sup> ` climits`&nbsp;<sup>**`1`**</sup> ` cmath`&nbsp;<sup>**`1`**</sup> ` valarray`&nbsp;<sup>**`1`**</sup> ` md5.hpp`&nbsp;<sup>**`1`**</sup> ` functional`&nbsp;<sup>**`1`**</sup> ` `

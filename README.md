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

## Non C++ Stuff

### Day 1 (Part 1): Bash-ism (85 chars)

```bash
(paste -s<(tr -dc '('<input1.txt|wc -c)<(tr -dc ')'<input1.txt|wc -c))|paste -sd-|bc
```

### Day 2: Bash-isms

#### Part 1: (125 chars)

```bash
<input2.txt while read line; do tr x \\n <<<$line|sort -n|paste -s|awk '{print 3*($1*$2)+2*$3*($1+$2);}';done|paste -sd+|bc
```

#### Part 2: (120 chars)

```bash
<input2.txt while read line; do tr x \\n <<<$line|sort -n|paste -s|awk '{print 2*($1*$2)+$1*$2*$3;}';done|paste -sd+|bc
```

### Day 10: Bash-ism (75 chars)

Note: `s` needs to contain the input string

```bash
for i in `seq 40`;do s=`fold -w1<<<$s|uniq -c|tr -d '\n '`;done;echo ${#s}
```

## Detailed Information

 Day | Lines | Code | Bytes | Chars | Time | Source | Headers
:---:|:-----:|:----:|:-----:|:-----:| ----:|:------:|:-------
01|18|11|393|283|0.0062|[day01.cpp](https://github.com/willkill07/adventofcode/blob/master/src/day01/day01.cpp)|*`io.hpp`* *`timer.hpp`* `iostream`
02|22|12|624|490|0.0052|[day02.cpp](https://github.com/willkill07/adventofcode/blob/master/src/day02/day02.cpp)|*`io.hpp`* *`timer.hpp`* `algorithm` `iostream` `regex` `string`
03|30|18|656|497|0.0078|[day03.cpp](https://github.com/willkill07/adventofcode/blob/master/src/day03/day03.cpp)|*`io.hpp`* *`timer.hpp`* `iostream` `map` `tuple`
04|16|8|510|408|0.4674|[day04.cpp](https://github.com/willkill07/adventofcode/blob/master/src/day04/day04.cpp)|*`io.hpp`* *`md5.hpp`* *`timer.hpp`* `iostream` `string`
05|17|8|630|517|0.0574|[day05.cpp](https://github.com/willkill07/adventofcode/blob/master/src/day05/day05.cpp)|*`io.hpp`* *`timer.hpp`* `iostream` `regex` `string`
06|59|38|1679|1272|0.4890|[day06.cpp](https://github.com/willkill07/adventofcode/blob/master/src/day06/day06.cpp)|*`io.hpp`* *`timer.hpp`* `functional` `future` `iostream` `iterator` `regex` `string` `vector`
07|76|51|2203|1592|0.0059|[day07.cpp](https://github.com/willkill07/adventofcode/blob/master/src/day07/day07.cpp)|*`io.hpp`* *`timer.hpp`* `iostream` `map` `regex` `string`
08|27|13|752|586|0.0064|[day08.cpp](https://github.com/willkill07/adventofcode/blob/master/src/day08/day08.cpp)|*`io.hpp`* *`timer.hpp`* `iostream` `iterator` `numeric` `regex` `string`
09|36|23|1070|844|0.0779|[day09.cpp](https://github.com/willkill07/adventofcode/blob/master/src/day09/day09.cpp)|*`timer.hpp`* `iostream` `limits` `map` `numeric` `set` `string` `vector`
10|24|14|676|508|0.0576|[day10.cpp](https://github.com/willkill07/adventofcode/blob/master/src/day10/day10.cpp)|*`io.hpp`* *`timer.hpp`* `algorithm` `iostream` `iterator` `vector`
**TOTAL**|**325**|**196**|**9193**|**6997**|**1.1808**| | *`timer.hpp`*&nbsp;<sup>**`10`**</sup> `iostream`&nbsp;<sup>**`10`**</sup> *`io.hpp`*&nbsp;<sup>**`9`**</sup> `string`&nbsp;<sup>**`7`**</sup> `regex`&nbsp;<sup>**`5`**</sup> `map`&nbsp;<sup>**`3`**</sup> `vector`&nbsp;<sup>**`3`**</sup> `iterator`&nbsp;<sup>**`3`**</sup> `algorithm`&nbsp;<sup>**`2`**</sup> `numeric`&nbsp;<sup>**`2`**</sup> `limits`&nbsp;<sup>**`1`**</sup> `future`&nbsp;<sup>**`1`**</sup> `tuple`&nbsp;<sup>**`1`**</sup> `set`&nbsp;<sup>**`1`**</sup> *`md5.hpp`*&nbsp;<sup>**`1`**</sup> `functional`&nbsp;<sup>**`1`**</sup>

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
01|18|11|393|283|0.0049|[day01.cpp](https://github.com/willkill07/adventofcode/blob/master/src/day01/day01.cpp)|`iostream` *`timer.hpp`* *`io.hpp`*
02|22|12|624|490|0.0054|[day02.cpp](https://github.com/willkill07/adventofcode/blob/master/src/day02/day02.cpp)|`algorithm` `iostream` `regex` `string` *`timer.hpp`* *`io.hpp`*
03|30|18|656|497|0.0077|[day03.cpp](https://github.com/willkill07/adventofcode/blob/master/src/day03/day03.cpp)|`iostream` `map` `tuple` *`timer.hpp`* *`io.hpp`*
04|16|8|510|408|0.4353|[day04.cpp](https://github.com/willkill07/adventofcode/blob/master/src/day04/day04.cpp)|`iostream` `string` *`md5.hpp`* *`timer.hpp`* *`io.hpp`*
05|17|8|630|517|0.0589|[day05.cpp](https://github.com/willkill07/adventofcode/blob/master/src/day05/day05.cpp)|`iostream` `string` `regex` *`timer.hpp`* *`io.hpp`*
06|59|38|1679|1272|0.4890|[day06.cpp](https://github.com/willkill07/adventofcode/blob/master/src/day06/day06.cpp)|`functional` `future` `iostream` `iterator` `regex` `string` `vector` *`timer.hpp`* *`io.hpp`*
07|67|45|2061|1510|0.0065|[day07.cpp](https://github.com/willkill07/adventofcode/blob/master/src/day07/day07.cpp)|`iostream` `map` `string` `regex` *`timer.hpp`* *`io.hpp`*
08|27|13|752|586|0.0061|[day08.cpp](https://github.com/willkill07/adventofcode/blob/master/src/day08/day08.cpp)|`iostream` `iterator` `numeric` `regex` `string` *`timer.hpp`* *`io.hpp`*
09|36|23|1070|844|0.0739|[day09.cpp](https://github.com/willkill07/adventofcode/blob/master/src/day09/day09.cpp)|`iostream` `limits` `map` `numeric` `set` `string` `vector` *`timer.hpp`*
10|24|14|676|508|0.0573|[day10.cpp](https://github.com/willkill07/adventofcode/blob/master/src/day10/day10.cpp)|`algorithm` `iostream` `iterator` `vector` *`timer.hpp`* *`io.hpp`*
11|41|27|927|644|0.0181|[day11.cpp](https://github.com/willkill07/adventofcode/blob/master/src/day11/day11.cpp)|`iostream` `string` *`timer.hpp`* *`io.hpp`*
**TOTAL**|**357**|**217**|**9978**|**7559**|**1.1631**| | *`timer.hpp`*&nbsp;<sup>**`11`**</sup> `iostream`&nbsp;<sup>**`11`**</sup> *`io.hpp`*&nbsp;<sup>**`10`**</sup> `string`&nbsp;<sup>**`8`**</sup> `regex`&nbsp;<sup>**`5`**</sup> `map`&nbsp;<sup>**`3`**</sup> `vector`&nbsp;<sup>**`3`**</sup> `iterator`&nbsp;<sup>**`3`**</sup> `algorithm`&nbsp;<sup>**`2`**</sup> `numeric`&nbsp;<sup>**`2`**</sup> `limits`&nbsp;<sup>**`1`**</sup> `future`&nbsp;<sup>**`1`**</sup> `tuple`&nbsp;<sup>**`1`**</sup> `set`&nbsp;<sup>**`1`**</sup> *`md5.hpp`*&nbsp;<sup>**`1`**</sup> `functional`&nbsp;<sup>**`1`**</sup>

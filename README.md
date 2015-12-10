# Advent of Code - 2015

All implementations are written in C++, strictly adhering to C++11/14 guidelines.

### Metrics

* Lines: Number of lines given by `wc`
* Code: `Lines` - `(# preprocessor lines)` - `(lines with no alphanumeric chars)`
* Bytes: Number of total characters
* Chars: Number of non-whitespace characters
* Time: Time in seconds to execute each part independently (separate runs)
* Source: link to implementation
* Headers: C++ includes used for solution

### Leaderboard Highlights:

* Day 5: Placed #60
* Day 8: Placed #14
* Day 10: Placed #64

### Non C++ Stuff

##### Day 1 (Part 1): Bash-ism (83 chars)

```bash
(paste -s<(tr -dc '('<input1.txt|wc -c)<(tr -dc ')'<input1.txt|wc-c))|paste -sd-|bc
```

##### Day 2 (Part 1): Bash-ism (123 chars)

```bash
<input2.txt while read line; do tr x \\n <<<$line|sort -n|paste -s|awk '{print 3*($1*$2)+2*$3*($1+$2);}';done|paste -sd+|bc
```

##### Day 10: Bash-ism (74 chars)

Note: `s` needs to contain the input string

```bash
for i in `seq 40`;do s=`fold -w1<<<$s|uniq -c|tr -d '\n '`;done;wc -c<<<$s
```

### Detailed Information

 Day | Lines | Code | Bytes | Chars | Time | Source | Headers
:---:|:-----:|:----:|:-----:|:-----:| ----:|:------:|:-------
01|18|12|367|257|0.0030|[day01.cpp](https://github.com/willkill07/adventofcode/blob/master/src/day01/day01.cpp)|`iostream`
02|22|13|656|515|0.0052|[day02.cpp](https://github.com/willkill07/adventofcode/blob/master/src/day02/day02.cpp)|`algorithm` `iostream` `regex` `string`
03|30|19|675|512|0.0071|[day03.cpp](https://github.com/willkill07/adventofcode/blob/master/src/day03/day03.cpp)|`iostream` `map` `tuple`
04|17|10|498|394|0.4196|[day04.cpp](https://github.com/willkill07/adventofcode/blob/master/src/day04/day04.cpp)|`iostream` `string`
05|17|9|626|515|0.0533|[day05.cpp](https://github.com/willkill07/adventofcode/blob/master/src/day05/day05.cpp)|`iostream` `regex` `string`
06|61|40|1714|1292|0.4599|[day06.cpp](https://github.com/willkill07/adventofcode/blob/master/src/day06/day06.cpp)|`functional` `future` `iostream` `iterator` `regex` `string` `vector`
07|78|54|2217|1598|0.0117|[day07.cpp](https://github.com/willkill07/adventofcode/blob/master/src/day07/day07.cpp)|`iostream` `map` `regex` `string`
08|27|13|855|666|0.0059|[day08.cpp](https://github.com/willkill07/adventofcode/blob/master/src/day08/day08.cpp)|`iostream` `iterator` `numeric` `regex` `string`
09|36|23|1070|844|0.0744|[day09.cpp](https://github.com/willkill07/adventofcode/blob/master/src/day09/day09.cpp)|`iostream` `limits` `map` `numeric` `set` `string` `vector`
10|22|13|658|496|0.0855|[day10.cpp](https://github.com/willkill07/adventofcode/blob/master/src/day10/day10.cpp)|`algorithm` `iostream` `iterator` `vector`
**TOTAL**|**328**|**206**|**9336**|**7089**|**1.1256**| | `algorithm` `functional` `future` `iostream` `iterator` `limits` `map` `numeric` `regex` `set` `string` `tuple`

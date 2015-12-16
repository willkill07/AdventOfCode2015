# Advent of Code - 2015

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

### Day 16: Abuse of `grep`

#### Part 1: (150 chars)

```bash
egrep -v 'children: [^3]|cats: [^7]|samoyeds: [^2]|pomeranians: [^3]|akitas: [^0]|vizslas: [^0]|goldfish: [^5]|trees: [^3]|cars: [^2]|perfumes: [^1]'
```

#### Part 2: (161 chars)

```bash
egrep -v 'children: [^3]|cats: [0-7]|samoyeds: [^2]|pomeranians: [^0-3]|akitas: [^0]|vizslas: [^0]|goldfish: (10|[5-9])|trees: [0-3]|cars: [^2]|perfumes: [^1],'
```

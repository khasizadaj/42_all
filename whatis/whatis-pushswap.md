# Push Swap

## Description

The Push swap project is a very simple and a highly straightforward algorithm project: *data must be sorted*.

You have at your disposal a set of integer values, 2 stacks, and a set of instructions to manipulate both stacks.

Your goal? Write a program in C called push_swap which calculates and displays on the standard output the smallest program, made of Push swap language instructions, that sorts the integers received as arguments.

## Rules

* You have 2 stacks named `a` and `b`.

* At the beginning:
	- The stack `a` contains a random amount of negative and/or positive numbers which cannot be duplicated.
	- The stack `b` is empty.

* The goal is to sort in ascending order numbers into stack `a`. To do so you have the following operations at your disposal:
	- `sa` (swap `a`): Swap the first 2 elements at the top of stack `a`. (*Note:* Do nothing if there is only one or no elements.)
	- `sb` (swap `b`): Swap the first 2 elements at the top of stack `b`. (*Note:* Do nothing if there is only one or no elements.)
	- `ss` : `sa` and `sb` at the same time.
	- `pa` (push `a`): Take the first element at the top of `b` and put it at the top of `a`. (*Note:* Do nothing if `b` is empty.)
	- `pb` (push `b`): Take the first element at the top of `a` and put it at the top of `b`. (*Note:* Do nothing if `a` is empty.)
	- `ra` (rotate `a`): Shift up all elements of stack `a` by 1. (*Note:* The first element becomes the last one.)
	- `rb` (rotate `b`): Shift up all elements of stack `b` by 1. (*Note:* The first element becomes the last one.)
	- `rr` : `ra` and `rb` at the same time.
	- `rra` (reverse rotate `a`): Shift down all elements of stack `a` by 1. (*Note:* The last element becomes the first one.)
	- `rrb` (reverse rotate `b`): Shift down all elements of stack `b` by 1.(*Note:* The last element becomes the first one.)
	- `rrr` : `rra` and `rrb` at the same time.

## Program

* Program name: `push_swap`
* Turn in files: `Makefile, *.h, *.c`
* Makefile commands: `NAME, all, clean, fclean, re`
* Allowed functions: `read, write, malloc, free, exit`
* Libft authorized: `yes`
* Other instructioins:
	- Instructions must be separated by a `\n` and nothing else.
	- The program must display the smallest list of instructions possible to sort the stack, the smallest number being at the top
	- The first argument should be at the top of the stack (be careful about the order)
	- If no parameters are specified, the program must not display anything and give the prompt back.
	- In case of error, it must display `Error` followed by a `\n` on the standard error. Errors include for example:
		* some arguments aren’t integers
		* some arguments are bigger than an integer
		* some arguments are duplicate

### Sample output

```bash
$ ./push_swap 2 1 3 6 5 8
sa
pb
pb
pb
sa
pa
pa
pa
```

```bash
$ ./push_swap 0 one 2 3
Error
$
```

```bash
$ ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
6
```

## References

- [Project](https://projects.intra.42.fr/projects/42cursus-push_swap)
- [Subject](https://cdn.intra.42.fr/pdf/pdf/111156/en.subject.pdf) - (Retrieved @ 15.12.2023)


---

NUmbers to test:

### 100

72   36   45   10   54   38   83   23   56   77   44   81   30   99   50    5   48   35   70    6   63   79   12    8   96   87   80   33    2   78   73   20   34   93   64   74   85   29   89   91   71   86   53   58   15   65   60   49   40   59    3  100   67   51   22   69    9   47   19   39   25   68   95   41   46   62   16   82   52   43   57   98   88   26   66   18   55   27   97   37   31   92    4   84   13   76   21   75   28   11   42   32   24   61   94   14   90    1   17    7

### 200 numbers

182  149  196   80   54   60   23  197  124  109  192  122   19   12   89   94   37  200  117    9   36   69   27   65   50  194   91   57  127   59   95   97   51  144   33  151   55   84  105  188  137  153   44  174   72   24   70   25  161  160  141   31  191    3  135   14    4  108  107  146  101  152  154  145  110  150  148   96   43   32  198  118  139   87   13   81  102  171   56   47   75  142  158    2  133   92   35   53   34   93  131   90   99   52  128  143   46  114   78   49 7  190   63  165   71   11   48   30   22  187  179  170   77   85  106  121   20  132   82   28  159  155  177  125  147  126  178  134  164   38   26   62  176   17  130   10  166  116  115   79  157  195   64   74   88   39  168   86  199  136   29   41    1  181   73  193  186  172   15   68  184  120   18  156    5  103  189    8  175  123  100  167   67  169   45   66  162  138  112   61  104   42  113   76  183   16   83   21  129  111  180  163  173  185   58   40  119   98    6  140
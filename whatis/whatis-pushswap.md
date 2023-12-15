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
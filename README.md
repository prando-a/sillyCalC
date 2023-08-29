# sillyCalC
Free-time-baked args calculator built in C. Not perfect but not malfunctional :)
Supports infinite arguments, different operations in the same execution and fractional output when necessary.

## Usage (General)
### `./[main.c compiled] [num] [+-"*"/] [num] ...`
The first (after execution argument) and the last argument must be numbers, and between two numbers there must be an operator sign.

* `./[main.c compiled] [-num] [operator] [+num]`
	- Negative and positive numbers are supported, no more than one sign per number.

* `./[main.c compiled] [num] "*" [num]`
	- Due to Linux environment conflicts, multiplication operator argument must be written as "*".

* `./[main.c compiled] [num]`
	- If only one number is prompted, the program will print it.

* The printed output will be fractional if needed up to 3 fractional digits, meaning that integer outputs will not be shown as fractional. <br>
- &nbsp; `./[main.c compiled] 40 + 2.420` <br>
Output: <br>
> 42.420 <br>
- &nbsp; `./[main.c compiled] 40 + 2` <br>
Output: <br>
> 42 <br>
* :x: Operators pointing to nowhere and invalid expressions will return an error, meaning that sillyCalC will first check arguments before doing anything. Examples: <br>
- &nbsp; `./[main.c compiled] +` <br>
- &nbsp; `./[main.c compiled] potato king` <br>
- &nbsp; `./[main.c compiled] 42 666 + 90` <br>
Output: <br>
> &nbsp; INVALID NUMBER AND / OR OPERATION

# sillyCalC
Free-time-baked args calculator built in C. Not perfect but not malfunctional :)
Supports infinite arguments, different operations in the same execution and fractional output when necessary.

## Usage
### ./[main.c compiled] [num] [+-"*"/] [num] ...
The first (after execution argument) and the last argument must be numbers, and between two numbers there must be an operator sign.
Due to Linux environment conflicts, multiplication operator argument must be written as "*".
Operators pointing to nowhere and invalid expressions will return an error.
If only one number is prompted, it will be printed.
The printed output will be fractional if needed, meaning that integer outputs will not be shown as fractional.

# java-sloc-count
A C program that reports the source lines of code for any Java program.
This program counts semicolon statements, non-blank and non-comment lines, ignores right braces and counts left braces. </br>
Output consists the number of lines following the above rules, and also the number of scopes "{...}" at each level (e.g. class, method, etc). </br>
For more assignment description see: http://gee.cs.oswego.edu/dl/csc344/a1.html

# Execution
To run, have any input Java program placed under the same directory and use command: </br>
`gcc -o java-sloc-count java-sloc-count.c` </br>
and then, </br>
`java-sloc-count`

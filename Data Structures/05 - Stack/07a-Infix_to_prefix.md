In case of infix to prefix, the method is quite similar to infix to postfix. There are only a few minor changes.
First of all, we traverse the string in reverse direction. Also, in case of infix to postfix, we pop off till the
time stack top is greater than or equal to the current character. However, in this case, we will pop off only for
strictly greater than (due to the fact that we encounter right operators first and do not wish to calculate them first).
Only in the case of ^ operator which is R to L, we pop off.
At the end, reverse the resultant string again

Evaluation of prefix is also quite similar, just the traversal is of the reverse string

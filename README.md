# What?

An implementation of Church encoding in C++. Church encoding is a way of writing standard types like boolean and numeric using mostly functions.

# Why?

Exploring Church encodings helps me understand functional programming better, because it's an extreme way of using functions / lambdas. Implementing it in more languages allows me to see the differences between languages.

# Details

There's only one file that implements the boolean Church encoding and tests for it. Four functions are used: TRUE, FALSE, IF and to_boolean. The tests show examples of usage.

To run it, just do make - it will automatically compile and run the code.

I used vim to create the code, with the YouCompleteMe plugin. The compile_commands.json file is used by the plugin for showing live compilation errors inside vim.

Feel free to use this code in anyway you like.

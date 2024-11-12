# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_convert.sh                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anferre <anferre@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/11 17:20:37 by anferre           #+#    #+#              #
#    Updated: 2024/11/12 11:22:22 by anferre          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

# Define the path to the executable
EXEC="./convert"

declare -a tests=(
    "42"            # Integer input
    "42.0"          # Double input
    "42.0f"         # Float input with 'f' suffix
    "'a'"           # Character input
	"' '"			# Space character
	"'\t'"			# Tab character
    "nan"           # Pseudo-literal for double
    "nanf"          # Pseudo-literal for float
    "+inf"          # Positive infinity for double
    "-inf"          # Negative infinity for double
    "+inff"         # Positive infinity for float
    "-inff"         # Negative infinity for float
	#int limits
    "2147483647"    # Maximum int value
	"2147483648"
    "-2147483648"   # Minimum int value
	"-2147483649"

	#float limits
	"3.40282e+38f"  # Maximum float value
    "3.40283e+38f"  # Just above float max (out of range)
    "-3.40282e+38f" # Minimum float value
    "-3.40283e+38f" # Just below float min (out of range)
    "1.17549e-38f"  # Smallest positive float
    "1.17548e-38f"  # Just below smallest positive float (rounds to zero)
	
	 # Double limits
    "1.79769e+308"  # Maximum double value
    "1.79770e+308"  # Just above double max (out of range)
    "-1.79769e+308" # Minimum double value
    "-1.79770e+308" # Just below double min (out of range)
    "2.22507e-308"  # Smallest positive double
    "2.22506e-308"  # Just below smallest positive double (rounds to zero)
	
    "0"             # Zero
    "non-numeric"   # Invalid input
)

for input in "${tests[@]}"; do
    echo "Testing input: $input"
    $EXEC "$input"
    echo "---------------------"
done

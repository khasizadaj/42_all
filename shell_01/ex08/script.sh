BASE_1='\\"?!'
BASE_1_LENGTH=5
BASE_1_NUMBERS='1234'
BASE_2='mrdoc'
BASE_3='gtaio luSnemf'

echo $BASE_1
echo $BASE_1_NUMBERS
echo $BASE_2
echo $BASE_3

FT_NBR1=\\\'\?\"\\\"\'\\
FT_NBR2="rcrdmddd"

# convert from BASE_1
echo $FT_NBR1 | tr $BASE_1 $BASE_1_NUMBERS | sed "s/'/0/g" | $(($BASE_1_LENGTH#10321201))
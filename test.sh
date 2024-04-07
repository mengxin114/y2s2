
#!/bin/bash

all_counter=0
pass_counter=0


echo -e "~~ Argument Tests ~~"

((all_counter++))
echo -n "test arguments error - "
./maze > temp
if grep -q "argument error" temp;
then
    echo -e "\e[32mPASS\e[0m"
    ((pass_counter++))
else
    echo -e "\e[31mFAIL\e[0m"
fi


((all_counter++))
echo -n "Testing 2 arguments - "
./maze x x > tmp
if grep -q "argument error" tmp;
then
    echo -e "\e[32mPASS\e[0m"
    ((pass_counter++))
else
    echo -e "\e[31mFAIL\e[0m"
fi




echo -e "\n~~ File Handling~~"

((all_counter++))
echo -n "Testing bad filename - "
timeout 0.2s ./maze bad.txt > tmp
if grep -q "Error: cannot find file" tmp;
then
    echo -e "\e[32mPASS\e[0m"
    ((pass_counter++))
else
    echo -e "\e[31mFAIL\e[0m"
fi

((all_counter++))
echo -n "too many Start point - "
timeout 0.2s ./maze ./testData/badData1.txt 24 7 > tmp
if grep -q "Error: file does not have expected format" tmp;
then
    echo -e "\e[32mPASS\e[0m"
    ((pass_counter++))
else
    echo -e "\e[31mFAIL\e[0m"
fi


((all_counter++))
echo -n "empty data - "
timeout 0.2s ./maze ./testData/emptyData.txt 24 7 > tmp
if grep -q "Error: file does not have expected format" tmp;
then
    echo -e "\e[32mPASS\e[0m"
    ((pass_counter++))
else
    echo -e "\e[31mFAIL\e[0m"
fi

((all_counter++))
echo -n "data wrong size - "
timeout 0.2s ./maze ./testData/wrongSize.txt 24 7 > tmp
if grep -q "Error: file does not have expected format" tmp;
then
    echo -e "\e[32mPASS\e[0m"
    ((pass_counter++))
else
    echo -e "\e[31mFAIL\e[0m"
fi


((all_counter++))
echo -n "Testing file loads successfully - "
./maze ./testData/rightSize.txt 25 8 > tmp
if grep -q "File successfully loaded." tmp;
then
    echo -e "\e[32mPASS\e[0m"
    ((pass_counter++))
else
    echo -e "\e[31mFAIL\e[0m"
fi

echo -e "\n~~ input ~~"

((all_counter++))
echo -n "Testing wrong input - "
./maze ./testData/rightSize.txt 25 8 < ./testInput/wrongInput.txt > temp
if grep -q "Wrong input" temp;
then
    echo -e "\e[32mPASS\e[0m"
    ((pass_counter++))
else
    echo -e "\e[31mFAIL\e[0m"


echo -e "\n~~ test basic function ~~"

((all_counter++))
echo -n "Testing wrong way - "
./maze ./testData/rightSize.txt 25 8 < ./testInput/wrongWay.txt > temp
if grep -q "can not pass" temp;
then
    echo -e "\e[32mPASS\e[0m"
    ((pass_counter++))
else
    echo -e "\e[31mFAIL\e[0m"

((all_counter++))
echo -n "Testing right way - "
./maze ./testData/rightSize.txt 25 8 < ./testInput/rightWay.txt > temp
if grep -q "win" temp;
then
    echo -e "\e[32mPASS\e[0m"
    ((pass_counter++))
else
    echo -e "\e[31mFAIL\e[0m"

((all_counter++))
echo -n "Testing show map - "
./maze ./testData/rightSize.txt 25 8 < ./testInput/showMap.txt > temp
if grep -q "#   X    #             #" temp;
then
    echo -e "\e[32mPASS\e[0m"
    ((pass_counter++))
else
    echo -e "\e[31mFAIL\e[0m"



((all_counter++))
echo -n "Testing win - "
./maze ./testData/rightSize.txt 25 8 < ./testInput/win.txt > temp
if grep -q "win" temp;
then
    echo -e "\e[32mPASS\e[0m"
    ((pass_counter++))
else
    echo -e "\e[31mFAIL\e[0m"






echo "Total tests: $all_counter"
echo "Passed tests: $pass_counter"
echo "Percentage passed: $(echo "scale=2; $pass_counter*100 / $all_counter" | bc)%"

#!/bin/bash

echo -e "~~ Argument Tests ~~"

echo -n "test arguments error - "
./maze > temp
if grep -q "arguments error" temp;
then
    echo "PASS"
else
    echo "FAIL"
fi


echo -n "Testing 2 arguments - "
./maze x x > tmp
if grep -q "arguments error" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi




echo -e "\n~~ File Handling~~"

echo -n "Testing bad filename - "
timeout 0.2s ./maze bad.txt > tmp
if grep -q "Error: cannot find file" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi


echo -n "too many S - "
timeout 0.2s ./maze ./testData/badData1.txt 24 7 > tmp
if grep -q "Error: file does not have expected format" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi


echo -n "empty data - "
timeout 0.2s ./maze ./testData/emptyData.txt 24 7 > tmp
if grep -q "Error: file does not have expected format" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi


echo -n "data wrong size - "
timeout 0.2s ./maze ./testData/wrongSize.txt 24 7 > tmp
if grep -q "Error: file does not have expected format" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi
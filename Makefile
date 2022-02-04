project: main.cpp Account.o savingsAccount.o currentAccount.o
	g++ main.cpp Account.o savingsAccount.o currentAccount.o -o project

Account.o: Account.cpp Account.h
	g++ -c Account.cpp

savingsAccount: savingsAccount.cpp savingsAccount.h
	g++ -c savingsAccount.cpp

currentAccount: currentAccount.cpp currentAccount.h
	g++ -c currentAccount.cpp

testLogin:
	./project < testLogin.txt | diff - expectedOutput01.txt

testWithdrawIncorrectInputs:
	./project < testWithdrawIncorrectInputs.txt | diff - expectedOutput02.txt

testWithdraw:
	./project < testWithdraw.txt | diff - expectedOutput03.txt

testDepositIncorrectInputs:
	./project < testDepositIncorrectInputs.txt | diff - expectedOutput04.txt

testDeposit:
	./project < testDeposit.txt | diff - expectedOutput05.txt

testTransferIncorrectInputs:
	./project < testTransferIncorrectInputs.txt | diff - expectedOutput06.txt

testTransfer:
	./project < testTransfer.txt | diff - expectedOutput07.txt

testViewBalanceIncorrectInputs:
	./project < testViewBalanceIncorrectInputs.txt | diff - expectedOutput08.txt

testViewAccountRecord:
	./project < testViewAccountRecord.txt | diff - expectedOutput09.txt

clean:
	rm -f *.o testUsername.txt project 
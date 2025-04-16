#include <iostream>
#include <string>
#include <vector>
#include <ctime> // لإدارة التواريخ
using namespace std;





void payment(float cost) {
	 creditCard card;
	 cout << "Enter card ID: ";
	 cin >> card.cardID;
	 cout << "Enter card CVV: ";
	 cin >> card.cardCVV;
	 cout << "Enter card name: ";
	 getline(cin, card.cardName);
	 cout << "Enter expiration date (YY/MM): ";
	 cin >> card.ExpirationDate;
	 card.balance = cost;


	 if (creditCard::validateCard(card)) {
		  cout << "Payment successful!" << endl;
	 }
	 else {
		  cout << "Payment failed!" << endl;
	 }

}

void reserveCourt(string courtID, string date,string) {


	
}

void main() {
	 cout << "04/15/2005" - "05/15/2005";
}

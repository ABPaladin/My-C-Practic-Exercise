#include <iostream>
#include <fstream>
using namespace std;
ofstream f;
ifstream A;
int biblioteca = 0;
struct Carti {
	int CodCarte;
	string Num_Pren_Autor;
	string Titlul;
	int AnEd;
	string Limba;
	int Pret;
	int Pag;
	string Tema;
	string temp;
};
Carti T[100];
void Inregistrare() {
	cout << "Inregistrarea Unei Noi Cartii\n" << "#################################" << endl;
	cout << "Introduceti Codul Carti: "; cin >> T[biblioteca].CodCarte;
	cout << "Introduceti Numele Si Prenumele Autorului: "; cin >> T[biblioteca].Num_Pren_Autor;
	cout << "Introduceti Titlul Cartii: "; cin >> T[biblioteca].Titlul;
	cout << "Introduceti Anul Catii: "; cin >> T[biblioteca].AnEd;
	cout << "Introduceti Limba Cartii: "; cin >> T[biblioteca].Limba;
	cout << "Introduceti Pretul Cartii: "; cin >> T[biblioteca].Pret;
	cout << "Introduceti Numarul De Pagini Al Cartii: "; cin >> T[biblioteca].Pag;
	cout << "Introduceti Tema Cartii: "; cin >> T[biblioteca].Tema;
	f.open("Carti.txt");
	for (int i = 0; i < biblioteca + 1; i++) {
		f << T[i].CodCarte << " " << T[i].Num_Pren_Autor << " " << T[i].Titlul << " " << T[i].AnEd << " " << T[i].Limba << " " << T[i].Pret << " " << T[i].Pag << " " << T[i].Tema << "\n";
	}
	f.close();
}
void Exclude() {
	string CinTema;
	cout << "Excluderea Unei Cartii Dupa Tematica\n" << "#############################################" << endl;
	cout << "Introduceti Tematica: "; cin >> CinTema;
	for (int i = 0; i < biblioteca; i++) {
		if (CinTema == T[i].Tema) {
			for (int q = i; q < biblioteca; q++) {
				T[q].CodCarte = T[q + 1].CodCarte;
				T[q].Num_Pren_Autor = T[q + 1].Num_Pren_Autor;
				T[q].Titlul = T[q + 1].Titlul;
				T[q].AnEd = T[q + 1].AnEd;
				T[q].Limba = T[q + 1].Limba;
				T[q].Pret = T[q + 1].Pret;
				T[q].Pag = T[q + 1].Pag;
				T[q].Tema = T[q + 1].Tema;
			}
			biblioteca = biblioteca - 1;
		}
	}
	f.open("Carti.txt");
	for (int i = 0; i < biblioteca; i++) {
		f << T[i].CodCarte << " " << T[i].Num_Pren_Autor << " " << T[i].Titlul << " " << T[i].AnEd << " " << T[i].Limba << " " << T[i].Pret << " " << T[i].Pag << " " << T[i].Tema << "\n";
	}
	f.close();
}
void Ordine() {
	int CinAn, k = 0, NrAutori = 0, x = 0;
	string str[10], temp;
	cout << "Autorii In Ordine Alfabetica Dupa Ani\n" << "#############################################" << endl;
	cout << "Introduceti Anul: "; cin >> CinAn;
	for (int i = 0; i < biblioteca; i++) {
		if (CinAn == T[i].AnEd) {
			str[k] = T[i].Num_Pren_Autor;
			k++;
			NrAutori++;
		}
	}
	for (int i = 0; i < NrAutori; i++) {
		for (int j = i + 1; j < NrAutori; j++) {
			if (str[i] > str[j]) {
				temp = str[i];
				str[i] = str[j];
				str[j] = temp;
			}
		}
	}
	while (x < NrAutori) {
		for (int i = 0; i < biblioteca; i++) {
			if (str[x] == T[i].Num_Pren_Autor) {
				cout << T[i].CodCarte << " " << T[i].Num_Pren_Autor << " " << T[i].Titlul << " " << T[i].AnEd << " " << T[i].Limba << " " << T[i].Pret << " " << T[i].Pag << " " << T[i].Tema << "\n";
				x++;
			}
		}
	}

}
void Romana() {
	int i = 0;
	f.open("Romana.txt");
	cout << "Inregistrarea Atributelor Cartilor Scrise In Limba Romana In Fisierul Romana.txt\n" << "#############################################" << endl;
	cout << "Introduceti titlul:"; cin >> T[biblioteca].Titlul;
	for (int i = 0; i < biblioteca; i++) {
		if (T[i].Limba == "Romana") {
			f << T[i].CodCarte << " " << T[i].Num_Pren_Autor << " " << T[i].Titlul << " " << T[i].AnEd << " " << T[i].Limba << " " << T[i].Pret << " " << T[i].Pag << " " << T[i].Tema << "\n";
		}
	}
	f.close();
}
void CarteNumMaxim() {
	int H[100], element;
	cout << "Seturile Atribuite Cartii Cu Cele Mai Multe Pagini\n" << "#############################################" << endl;
	for (int i = 0; i < biblioteca; i++) {
		H[i] = T[i].Pag;
	}
	for (int i = 0; i < biblioteca; i++) {
		for (int j = i + 1; j < biblioteca; j++) {
			if (H[j] < H[i]) {
				element = H[i];
				H[i] = H[j];
				H[j] = element;
			}
		}
	}
	for (int i = 0; i < biblioteca; i++) {
		if (H[biblioteca - 1] == T[i].Pag) {
			cout << T[i].CodCarte << " " << T[i].Num_Pren_Autor << " " << T[i].Titlul << " " << T[i].AnEd << " " << T[i].Limba << " " << T[i].Pret << " " << T[i].Pag << " " << T[i].Tema << "\n";
		}
	}
}
void PretCarteStraina() {
	int i = 0, CartiStr = 0, CartiSrtMed = 0;
	cout << "Pretul Mediu Al Cartilor Straine\n" << "#############################################" << endl;
	for (int i = 0; i < biblioteca; i++) {
		if (T[i].Limba != "Romana") {
			CartiSrtMed = CartiSrtMed + T[i].Pret;
			CartiStr++;
		}
	}
	cout << "Pretul Mediu Al Unei Carti Straine: " << CartiSrtMed / CartiStr;
}
int main() {
	int Varianta;
	A.open("Carti.txt");
	while (!A.eof()) {
		A >> T[biblioteca].CodCarte >> T[biblioteca].Num_Pren_Autor >> T[biblioteca].Titlul >> T[biblioteca].AnEd >> T[biblioteca].Limba >> T[biblioteca].Pret >> T[biblioteca].Pag >> T[biblioteca].Tema;
		if (T[biblioteca].CodCarte != 0) {
			biblioteca++;
		}
	}
	A.close();
	cout << "#############################################" << endl;
	cout << "1# Inregistreaza o noua carte" << endl;
	cout << "2# Exclude din fisierul Carti.txt, liniile, ce corespund cartilor cu tematica indicata de la tastatura" << endl;
	cout << "3# Afiseaza pe ecran seturile de atribute ale tuturor cartilor, editate dupa anul introdus de la tastatura, ordonandu-le alfabetic dupa numele_prenumele autorilor" << endl;
	cout << "4# Creeaza fisierul textual Romana.txt, ce va inregistra atributele cartilor scrise in limba romana, avand titlul indicat de la tastatura" << endl;
	cout << "5# Afiseaza pe ecran seturile de atribute ale cartii cu numarul maximal de pagini" << endl;
	cout << "6# Determina pretul mediu al cartilor editate limba straina" << endl;
	cout << "#############################################" << endl;
	cout << "Alegeti Varianta: "; cin >> Varianta;
	cout << "#############################################" << endl;
	if (Varianta == 1) Inregistrare();
	else if (Varianta == 2) Exclude();
	else if (Varianta == 3) Ordine();
	else if (Varianta == 4) Romana();
	else if (Varianta == 5) CarteNumMaxim();
	else if (Varianta == 6) PretCarteStraina();
	else cout << "Eroare!";
	return 0;
}
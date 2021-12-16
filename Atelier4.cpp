#include <iostream>
#include <set>
#include <vector>
#include <list>

using namespace std;

//Programme 1
class Complex
{
public:
    float real;
    float imaginary;
    void setValue(float re,float im);
    Complex operator+(Complex);
    Complex operator-(Complex);
    Complex operator*(Complex);
    Complex operator/(Complex);
};

void Complex::setValue(float re,float im)
{
    real = re;
    imaginary = im;
}

Complex Complex::operator+(Complex second){
    Complex result;
    result.imaginary = this->imaginary + second.imaginary;
    result.real = this->real + second.real;
    return result;
}

Complex Complex::operator-(Complex second){
    Complex result;
    result.imaginary = this->imaginary - second.imaginary;
    result.real = this->real - second.real;
    return result;
}

Complex Complex::operator*(Complex second){
    Complex result;
    result.real = this->real * second.real - this->imaginary * second.imaginary;
    result.imaginary = this->real * second.imaginary + this->imaginary * second.real;
    return result;
}


Complex Complex::operator/(Complex second){
    Complex result;
       result.real = (this->real * second.real + this->imaginary * second.imaginary) /
                (second.real * second.real + second.imaginary * second.imaginary);
        result.imaginary = (this->imaginary * second.real - this->real * second.imaginary) /
                (second.real * second.real + second.imaginary * second.imaginary);
    return result;
}
     

Complex arithmetics(Complex first,Complex second){
    Complex result;  
    float tempRe,tempIm;
    char operation ;
    
    cout << "Operation: \n";
    cout << "1: +\n";
    cout << "2: -\n";
    cout << "3: *\n";
    cout << "4: /\n";
    cin >> operation;

    
    switch (operation)
    {
    case '1':
        result = first + second;
        break;
     case '2':
        result = first - second;
        break;
     case '3':
        result = first * second;        
        break;
     case '4':
        result = first / second;
        break;
    }

    return result;
    
}

int main(int argc, char const *argv[])
{
    float tempRe,tempIm;

    Complex z1,z2;
    
    cout << "Entre la valeur reel: " << endl;
    cin >> tempRe;
    cout << "Entre la valeur imaginaire: " << endl;
    cin >> tempIm;
    z1.setValue(tempRe,tempIm);

    cout << "Entre la valeur reel: " << endl;
    cin >> tempRe;
    cout << "Entre la valeur imaginaire: " << endl;
    cin >> tempIm;
    z2.setValue(tempRe,tempIm);

    cout << "Le Nombre z1: " << z1.real << " + " << z1.imaginary << "i \n";
    cout << "Le Nombre z2: " << z2.real << " + " << z2.imaginary << "i \n";
    Complex result = arithmetics(z1,z2);

    cout << "Le resultat est: " << result.real << " + " << result.imaginary << "i \n";

    return 0;
}

	
//Programme 2
	class Test{
		public:
		static int tableau[] ;
		
		public :
		static int division(int indice, int diviseur){
		return tableau[indice]/diviseur;
		}
	};
	
	int Test::tableau[] = {17, 12, 15, 38, 29, 157, 89, -22, 0, 5} ;
	
	int main()
	{
		int x, y;
		
			cout << "Entrez l\'indice de l\'entier a diviser: " << endl;
			cin >> x ;
			cout << "Entrez le diviseur: " << endl;
			cin >> y ;
			cout << "Le resultat de la division est: "<< endl;
			cout <<Test::division(x,y) << endl;
			
		return 0;
	}

//Programme 3
void printList(list<int> mylist)
{
    
    list<int>::iterator it;
  

    for (it = mylist.begin(); it != mylist.end(); ++it)
        cout << ' ' << *it;
    cout << '\n';
}
  
int main()
{   int n;

   list<int> myList;

  
  for(int i=0;i<4;i++){
      cout<<"n : ";
       cin>>n;
      myList.push_back(n);
  }
  
 printList(myList);
  myList.sort();
  printList(myList);
    return 0;
}

//Programme 5
bool doesExistInSet(set <int> setToTest,int target){
    int temp = setToTest.count(target);
    if (temp==1)
    {
        return true;
    }
    
    return false;
}

bool anotherDoesExistInSet
    (set <int>::iterator begin,set <int>::iterator end,int target)
{
    for(set <int>::iterator setIterator = begin; setIterator!=end;setIterator++){
        if(*setIterator == target){
            return true;
        }
    }
    return false;
}

template <typename Iterable,typename Target,typename Iterator,typename Begin,typename End> 
bool isInField(Iterable field,Iterator iterator,Target target,Begin begin,End end){
     for(
         iterator = begin;
         iterator != end;
         iterator++
         ){
        if(*iterator == target){
            return true;
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    set <int> mySet;
    set <int>::iterator setIterator;
    int target;

    for(int i = 1;i <= 100; i++){
        mySet.insert(i);
    }

    cout << "Entrer une valeur a chercher\n";
    cin >> target;
    if(doesExistInSet(mySet,target)){
        cout << "Cet entier " << target << " existe dans le set.\n";
    }else{
        cout << "Cet entier " << target << " n'existe pas dans le set.\n";
    }

    cout << "=========utilisation d'une autre methode============\n";
     if(anotherDoesExistInSet(mySet.begin(),mySet.end(),target)){
        cout << "Cet entier " << target << " existe dans le set.\n";
    }else{
        cout << "Cet entier " << target << " n'existe pas dans le set.\n";
    }
    cout << "=========utilisation d'une template methode============\n";
     if(isInField(mySet,setIterator,target,mySet.begin(),mySet.end())){
        cout << "Cet entier " << target << " existe dans le set.\n";
    }else{
        cout << "Cet entier " << target << " n'existe pas dans le set.\n";
    }
    
    cout << "=========utilisation d'une template methode avec un vecteur de string============\n";
    vector <string> myVector = {"aya","harfouch"} ;
    vector <string>::iterator vectorIterator;
    if(isInField(myVector,vectorIterator,"aya",myVector.begin(),myVector.end())){
    cout << "Cette valeur " << "aya" << " existe dans le vecteur.\n";
    }else{
        cout << "Cette valeur " << "aya" << " n'existe pas dans le vecteur.\n";
    }

    cout << "=========utilisation d'une template methode avec un liste d'entiers============\n";
    list <int> myList;
    list <int>::iterator listIterator;
    
    for(int i = 1;i <= 100; i++){
        myList.push_back(i);
    }
    if(isInField(myList,listIterator,target,myList.begin(),myList.end())){
    cout << "Cet entier " << target << " existe dans la liste.\n";
    }else{
        cout << "Cet entier " << target << " n'existe pas dans la liste.\n";
    }

    cout << "=========utilisation d'une template methode avec un tableau de floats============\n";
    float classicTable[100];
    float* classicTableIterator = classicTable;
    for(int i = 1;i <= 100;i++){
        classicTable[i-1] = i;
    }
    if(isInField(classicTable,classicTableIterator,target,&classicTable[0],&classicTable[100])){
    cout << "Cette valeur " << target << " existe dans la table des floats.\n";
    }else{
        cout << "Cette valeur " << target << " n'existe pas dans la table des floats.\n";
    }
    
    return 0;
}

//Programme 7
// class Animal
class Animal{
    protected:
    string nom;
    int age;
    string genre;

    public:
    void setNom(string nom);
    void setAge(int age);
    void setGenre(string genre);
    string getNom();
    int getAge();
    string getGenre();
};

void Animal::setNom(string nom){
    this ->nom = nom;
}
void Animal::setAge(int age){
    this ->age = age;
}
void Animal::setGenre(string genre){
    this ->genre = genre;
}
string Animal::getNom(){
    return this ->nom;
}
int Animal::getAge(){
    return this ->age;
}
string Animal::getGenre(){
    return  this ->genre;
}
// class Repas, Element
class Element{
    private:
    string nom;
    string type;
    public:
    void setNom(string nom){
        this->nom = nom;
    }
    void setType(string type){
        this -> type = type;
    }
    string getNom(){
        return this->nom;
    }
    string getType(){
        return this -> type;
    }
};

class Repas{
    private:
    string nom;
    int heure;
    string description;
    list <Element> elementsList;
    public:
    void setNom(string nom){
        this->nom = nom;
    }
    void setHeure(int heure){
        this->heure = heure;
    }
    void setDescription(string description){
        this->description = description;
    }
    void setElementsList(list <Element> elementsList){
        this->elementsList = elementsList;
    }
    string getNom(){
        return this->nom;
    }
    int getHeure(){
        return this->heure;
    }
    string getDescription(){
        return this->description;
    }
    list <Element> getElementsList(){
        return this->elementsList;
    }
};
// class Chat
class Chat: public Animal{
    private:
    string type;
    Repas chatRepas;
    public:
    void setType(string type){
        this -> type = type;
    }
    void setRepas(Repas chatRepas){
        this->chatRepas = chatRepas;
    }
    string getType(){
        return this -> type;
    }
    Repas getRepas(){
        return this->chatRepas;
    }
    void sauter(){
        cout << "  \n";
    }
};
// class Race
class Race{
    protected:
    string specifite;
    bool isRaceHybride(){
        if (specifite=="  "){
            return true;
        }
        return false;
    }
    public:
    void setSpecifite(string specifite){
        this->specifite = specifite;
    }
    string getSpecifite(){
        return this->specifite;
    }
};

// class Chien
class Entraineur;
class Chien:public Animal,Race{
    private:
    string taille;
    list <Entraineur> entraineurList;
    public:
    
    void setTaille(string taille){
        this->taille = taille;
    }
    void setEntraineurList(list <Entraineur> entraineurList){
        this->entraineurList = entraineurList; 
    }
    
    string getTaille(){
        return this->taille;
    }
    list <Entraineur> getEntraineurList(){
        return this->entraineurList;
    }
    
    bool isChass3(){
        return true;
    }
};

// class Entraineur
class Entraineur{
    private:
    string nom;
    string description;
    list <Chien> chienList;
    public:
    
    void setNom(string nom){
        this->nom = nom;
    }
    void setDescription(string description){
        this->description = description;
    }
    void setChienList(list <Chien> chienList){
        this->chienList = chienList;
    }

    string getNom(){
        return this->nom;
    }
    string getDescription(){
        return this->description;
    }
    list <Chien> getChienList(){
        return this->chienList;
    }
};

// class Compitition
class Compitition{
    private:
    string date;
    string nom;
    Chien chien;
    Entraineur entraineur;
    public:
    int ordre;
    
    void setDate(string date){
        this->date = date;
    }
    void setNom(string nom){
        this->nom = nom;
    }
    void setChien(Chien chien){
        this->chien = chien;
    }
    void setEntraineur(Entraineur entraineur){
        this->entraineur = entraineur;
    }
 
    string getDate(){
        return this->date;
    }
    string getNom(){
        return this->nom;
    }
    Chien getChien(){
        return this->chien;
    }
    Entraineur getEntraineur(){
        return this->entraineur;
    }
};

int main(int argc, char const *argv[])
{
  
    list <Element> myElements;
    Element el1,el2;
    el1.setNom("Element 1");
    el1.setType("Type 1");
    el2.setNom("Element 2");
    el2.setType("Type 2");
    myElements.push_back(el1);
    myElements.push_back(el2);
  
    Repas myRepas;
    myRepas.setNom("Repas 1");
    myRepas.setHeure(3);
    myRepas.setDescription("Description 1");
    myRepas.setElementsList(myElements);
   
    Chat tom;
    tom.setNom("Jack");
    tom.setGenre("male");
    tom.setAge(3);
    tom.setRepas(myRepas);
    tom.setType("blue");
    tom.sauter();
    
    Chien spike;
    spike.setNom("Tayzen");
    spike.setGenre("male");
    spike.setAge(5);
    spike.setTaille("4");
    list <Chien> chienList;
    chienList.push_back(spike);
    
    Entraineur myEntraineur;
    myEntraineur.setNom("Haitam");
    myEntraineur.setChienList(chienList);
    myEntraineur.setDescription("Excptional coach.");
    list <Entraineur> entraineurList;
    entraineurList.push_back(myEntraineur);
    spike.setEntraineurList(entraineurList);
    
    Compitition firstCompitition;
    firstCompitition.setNom("CHAMPIONS LEAGE");
    firstCompitition.setDate("13/05/2018");
    firstCompitition.setChien(spike);
    firstCompitition.setEntraineur(myEntraineur);

   

    cout << "\n\nCompetition\n";
    cout << firstCompitition.getNom() << "\n";
    cout << firstCompitition.getDate() << "\n";
    cout << firstCompitition.getEntraineur().getNom() << "\n";
    cout << firstCompitition.getEntraineur().getDescription() << "\n";
    cout << firstCompitition.getChien().getNom() << "\n";


    list <Element>::iterator elementIterator;
    cout << "\nIterator\n";
    elementIterator = myRepas.getElementsList().begin(); 
    cout << elementIterator->getNom() << "\n";
    cout << elementIterator->getType() << "\n";
    
    
    return 0;
}	

#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

int i, j;
int numberOfLevels = 0;
int maxLevels;
int quick = 0, heap = 0, selection = 0;

void heapSort(vector<int>& arrayToSort, int left, int right);
void maxHeap(vector<int>& arrayToSort, int left, int right, int parentPosition);
bool sorted(vector<int>& arrayToSort, int left, int right);
int pivotChoice(int &left, int &center, int &right);
void quickSort(vector<int>& arrayToSort, int left, int right);
void selectionSort(vector<int>& arrayToSort, int left, int right);

int main() {
    srand(time(NULL));
    cout << "Podaj ilosc danych: " << endl;
    int dane;
    cin >> dane;
    //ODCZYT DANYCH Z PLIKU
    string filePath;
    cin >> filePath;
    ofstream fileStart(filePath.c_str());
    for(i = 0; i < dane; ++i) {
        if(i+1 < dane) fileStart << rand() + 1 << endl;
        else fileStart << rand() + 1;
    }
    fileStart.close();
    ifstream file(filePath.c_str());
    int component;
    vector<int> arrayToSort;
    while(file >> component) {
        arrayToSort.push_back(component);
    }
    file.close();
    //WYWOLANIE SORTOWANIA
    maxLevels = 2*(log2(arrayToSort.size()));
    quickSort(arrayToSort, 0, arrayToSort.size()-1);
    //ZMIANA SCIEZKI NA NOWA
    int length = filePath.length();
    filePath = filePath.erase(length - 4, length);
    filePath += ".out.txt";
    //ZAPIS DO PLIKU
    ofstream outFile(filePath.c_str());
    for(i = 0; i < arrayToSort.size(); ++i ) {
        if(i + 1 < arrayToSort.size()) outFile << arrayToSort[i] << endl;
        else outFile << arrayToSort[i];
    }
    outFile.close();
    cout << "QUICKSORT: " << quick << " HEAPSORT: " << heap << " SELECTIONSORT: " << selection << endl;
    //sprawdzam czy posortowane
    cout << sorted(arrayToSort, 0, arrayToSort.size()-1);
}
//HEAPSORT
void heapSort(vector<int>& arrayToSort, int left, int right) {
    heap++;
    //zaczynam od pozycji ostatniego rodzica
    for(i = left + ((right - left + 1) / 2) - 1; i >= left; --i) {
        maxHeap(arrayToSort, left, right, i);
    }
    for(i = right; i > left; --i) {
        swap(arrayToSort[left], arrayToSort[i]);
        --right;
        maxHeap(arrayToSort, left, right, left);
    }
}

void maxHeap(vector<int>& arrayToSort, int left, int right, int parentPosition) {
    //wynaczenie najwiekszego elementu sposrod dzieci i rodzicow, zamiana jesli nie pasuje
    int maxPosition = parentPosition;
    int leftChild = (parentPosition - left) * 2 + left + 1;
    int rightChild = (parentPosition - left) * 2 + left + 2;

    if(leftChild <= right && arrayToSort[maxPosition] < arrayToSort[leftChild]) {
        maxPosition = leftChild;
    }
    if(rightChild <= right && arrayToSort[maxPosition] < arrayToSort[rightChild]) {
        maxPosition = rightChild;
    }
    if(maxPosition != parentPosition) {
        swap(arrayToSort[maxPosition], arrayToSort[parentPosition]);
        maxHeap(arrayToSort, left, right, maxPosition);
    }
}

bool sorted(vector<int>& arrayToSort, int left, int right) {
    //sprawdza czy posortowana
    for(i = left; i < right; ++i) {
        if(arrayToSort[i] > arrayToSort[i+1]) return false;
    }
    return true;
}
//HEAPSORT
//QUICKSORT
int pivotChoice(int &left, int &center, int &right) {
    if(left > center) swap(left, center);
    if(left > right) swap(left, right);
    if(center > right) swap(center, right);
    return center;
}

void quickSort(vector<int>& arrayToSort, int left, int right) {
    ++numberOfLevels;
    quick++;
    if(right - left < 5) {
        selectionSort(arrayToSort, left, right);
    }
    else if(numberOfLevels > maxLevels) {
        if(!sorted(arrayToSort, left, right)){
            heapSort(arrayToSort, left, right);
        }
    } else {
        int center = (left+right)/2;
        //ustalenie med3
        int pivot = pivotChoice(arrayToSort[left], arrayToSort[center], arrayToSort[right]);
        if(pivot == arrayToSort[left]) swap(arrayToSort[left], arrayToSort[right]);
        else if(pivot == arrayToSort[center]) swap(arrayToSort[center], arrayToSort[right]);
        //poczatek sortowania
        int placeOfDevision = left-1;
        for(i = left; i < right; ++i) {
            if(arrayToSort[i] < pivot) {
                ++placeOfDevision;
                if(placeOfDevision != i) swap(arrayToSort[i], arrayToSort[placeOfDevision]);
            }
        }
        ++placeOfDevision;
        if(placeOfDevision != right) swap(arrayToSort[placeOfDevision], arrayToSort[right]);
        quickSort(arrayToSort, left, placeOfDevision-1);
        quickSort(arrayToSort, placeOfDevision+1, right);
    }
    --numberOfLevels;
}
//QUICKSORT
//SELECTIONSORT
void selectionSort(vector<int>& arrayToSort, int left, int right) {
    ++selection;
    for(i = left; i <= right; ++i) {
        int temp = i;
        for(j = i+1; j <= right; ++j) {
            if(arrayToSort[j] < arrayToSort[temp]) temp = j;
        }
        swap(arrayToSort[i], arrayToSort[temp]);
    }
}
//SELECTIONSORT

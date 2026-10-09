#pragma once

__declspec(dllexport) void fillArrRandom(int* arr, int size, int min, int max);
__declspec(dllexport) void printArr(int* arr, int size);
__declspec(dllexport) void processArr(int* arr, int size);

//__declspec Ч это ключевое слово Microsoft дл€ задани€ расширенных атрибутов, которое принимает 
// аргумент dllexport, чтобы экспортировать функцию из DLL дл€ использовани€ во внешних программах.
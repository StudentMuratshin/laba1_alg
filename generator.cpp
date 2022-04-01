#include "Generator.h"
#include <iostream>
#include <algorithm>
#include <numeric>

void Generator::Print(std::vector<int> v)
{
	std::fill(x.begin(), x.begin() + n, 0);
	for (auto s : v)
	{
		x[s] = 1;
	}
	for (auto s : x)
	{
		std::cout << s << ' ';
	}
	std::cout << std::endl;
}

std::vector<int> Generator::Reset(int id)
{
	if (id == k - 1) return index;
	int start = n - (k - id) + 1;
	index[id + 1] = start;
	for (int i = id + 2; i < k; i++)
	{
		index[i] = index[i - 1] + 1;
	}
	return index;
}

void Generator::clear()
{
	x.resize(n, 0);
	index.clear();
}


Generator::Generator(int n, int k) : n(n), k(k)
{
	x.resize(n, 0);
	std::fill(x.begin() + n - k, x.begin() + n, 1);
	for (int i = 0; i < x.size(); i++)
	{
		if (x[i] == 1) index.push_back(i);
	}
	Print(index);
}


void Generator::Generate()
{

	while (true)
	{
		for (int i = 0; i < k; i++)
		{
			if (index[k - 1] == k - 1)
			{
				clear();
				return;
			}

			if (i == k - 1)
			{
				index[i]--;

				while (n - 1 - index[i] < 3)
				{
					index[i]--;
				}

				if (k == 1)
				{
					if (index[0] < 3)
					{
						index[0] = 0;
					}
					defoult++;
					Print(index);
					continue;
				}

				if ((index[i] - index[i - 1]) <= 3)
				{
					while ((index[i] - index[i - 1]) != 1)
					{
						index[i]--;
					}
				}
				defoult++;
				Print(index);
			}

			else if (i == 0)
			{
				if (index[0] == 0) continue;
				if (Check(index, i)) continue;
				index[0]--;
				Reset(i);
				while ((index[i + 1] - index[i]) <= 3)
				{
					index[i]--;
				}
				if (index[i] < 3)
				{
					index[i] = 0;
				}
				defoult++;
				Print(index);
			}



			else
			{
				if (Check(index, i)) continue;
				index[i]--;
				Reset(i);
				while ((index[i + 1] - index[i]) <= 3)
				{
					index[i]--;
				}
				if ((index[i] - index[i - 1]) <= 3)
				{
					while ((index[i] - index[i - 1]) != 1)
					{
						index[i]--;
					}
				}
				defoult++;
				Print(index);
			}
		}
	}
}

bool Generator::Check(std::vector<int>, int id)
{
	int S = 0;
	for (int j = 0; j < k - id; j++)
	{
		S = S + index[id] + j;
	}
	if (S != accumulate(index.begin() + id, index.end(), 0))
	{
		return true;
	}
	else
	{
		return false;
	}
}


void Generator::Rec(int id, int prev)
{
	if (id == k) id = prev = 0;
	//if (Check(index, id)) { prev = index[id]; id++; }
	if (Check(index, id)) { Rec(id + 1, index[id]); }
	if (index[k - 1] == k - 1) return;
	Reset(id);
	index[id]--;
	int kol = k - id - 1;
	while (n - 1 - index[id] < kol + 3)
	{
		index[id]--;
	}
	if (abs(prev - index[id]) <= 3)
	{
		if (id == 0 && index[0] != 3) index[0] = 0;
		else if (id == 0 && index[0] == 3) index[0] = 3;
		else index[id] = prev + 1;
	}
	rec++;
	Print(index);
	if (id == k - 1 && index[0] == 0) Rec(1, 0);
	else Rec(id + 1, index[id]);
}



//void Generator::Rec(int id)
//{
//	count_rec++;
//	for (int i = k - id; i < k; i++)
//	{
//		if (index[k - 1] == k - 1)
//		{
//			//clear();
//			return;
//		}
//
//		if (i == k - 1)
//		{
//			index[i]--;
//
//			while (n - 1 - index[i] < 3)
//			{
//				index[i]--;
//			}
//
//			if (k == 1)
//			{
//				if (index[0] < 3)
//				{
//					index[0] = 0;
//				}
//				Print(index);
//				Rec(k);
//				continue;
//			}
//
//			if ((index[i] - index[i - 1]) <= 3)
//			{
//				while ((index[i] - index[i - 1]) != 1)
//				{
//					index[i]--;
//				}
//			}
//			Print(index);
//			Rec(k);
//		}
//
//		else if (i == 0)
//		{
//			if (Check(index, i, 0)) continue;
//			index[0]--;
//			Reset(i);
//			while ((index[i + 1] - index[i]) <= 3)
//			{
//				index[i]--;
//			}
//			if (index[i] < 3)
//			{
//				index[i] = 0;
//			}
//			Print(index);
//			Rec(k - i - 1);
//		}
//
//		else
//		{
//			if (Check(index, i, 0)) continue;
//			index[i]--;
//			Reset(i);
//			while ((index[i + 1] - index[i]) <= 3)
//			{
//				index[i]--;
//			}
//			if ((index[i] - index[i - 1]) <= 3)
//			{
//				while ((index[i] - index[i - 1]) != 1)
//				{
//					index[i]--;
//				}
//			}
//			Print(index);
//			Rec(k - i - 1);
//		}
//	}
//}



//void Generator::Rec(int id, int prev)
//{
//	if (id == k) id = prev = 0;   // если задействован первый элемент
//	if (index[id] == id && id != k - 1) Rec(id + 1, index[id]);	// если элемент уже стоит на своём финальном месте
//	if (index[k - 1] == k - 1) return;
//	int kol = k - id - 1;
//	index[id]--;
//	if (n - 1 - index[id] >= kol + 3 && abs(prev - index[id]) > 3)
//	{
//		Reset(id);
//		Print(index);
//		Rec(id + 1, index[id]);
//	}
//	else if (abs(prev - index[id]) <= 3) //если два друга встали слишком близко
//	{
//		if (id == 0 && index[0] != 3)   // если первый друг не стоит на 3 месте, то двигаем его до финальной точки 
//		{
//			Reset(id);
//			if (index[0] == 0) Print(index);	// вывожу в том случае, если наш товарищ УЖЕ на финальном месте (иначе будет выводить своё путешествие 
//			Rec(id, 0);																										//до финальной точки)
//			if (index[k - 1] == k - 1) return;
//		}
//		else if (id == 0 && index[0] == 3) { Reset(id); Print(index); Rec(id + 1, index[id]); if (index[k - 1] == k - 1) return; } //если друг на третьем месте, то остальных товарищей возвращаем домой, и рассматриваем уже некст друга
//		index[id] = prev + 1; // приказываем встать сзади предыдущего
//		Reset(id);	//домой возвращаем
//		Print(index); //фотографируем друзей
//		Rec(id + 1, index[id]); //вызываем следующего друга и уведомляем местоположение предыдущего товарища
//	}
//	else { if (id == 0) Rec(id, 0); else Rec(id, index[id - 1]); } // если вдруг товарищу не угодило ни одно место, то отправляем его повторно кататься
//	//в случае если первый товарищ, то вместе с ним отправляем нулевые координаты, потому что у него нет друзей сзади
//}
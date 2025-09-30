#include <cstddef>
#include <iostream>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>


struct ListNode
{
	int												val;
	std::unique_ptr<ListNode> next;
	ListNode() : val(0), next(nullptr)
	{}
	ListNode(int x) : val(x), next(nullptr)
	{}
	ListNode(int x, ListNode *next) : val(x), next(next)
	{}

	static std::unique_ptr<ListNode> stringToList(std::string str)
	{
		if (str.length() < 2)
			throw std::invalid_argument("Less than 2 chars.");

		str.erase(0, 1);
		str.erase(str.length() - 1); // I didn't get why there's size no lenght

		std::stringstream sstr(str);
		std::string				strPart;

		std::unique_ptr<ListNode> pList, pPreviousList = nullptr;
		while (getline(sstr, strPart, ' '))
		{
			pList = std::make_unique<ListNode>(ListNode(stoi(strPart)));

			if (pPreviousList == nullptr)
			{
				pPreviousList = std::move(pList);
				continue;
			}

			pPreviousList->next = std::move(pList);
		}

		return pList;
	}
};


class Solution
{
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
	{}
};

int main()
{
	std::string firstList, secondList;

	std::getline(std::cin, firstList);
	std::getline(std::cin, secondList);


	return 0;
}

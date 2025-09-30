#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <math.h>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <iostream>

struct ListNode
{
	int												val;
	std::shared_ptr<ListNode> next;
	ListNode() : val(0), next(nullptr)
	{}
	ListNode(int x) : val(x), next(nullptr)
	{}
	ListNode(int x, ListNode *next) : val(x), next(next)
	{}

	static std::shared_ptr<ListNode> stringToList(std::string str)
	{
		if (str.length() < 2)
			throw std::invalid_argument("Less than 2 chars.");

		str.erase(0, 1);
		str.erase(str.length() - 1); // I didn't get why there's size no length

		std::stringstream sstr(str);
		std::string				strPart;

		std::shared_ptr<ListNode> head;
		std::shared_ptr<ListNode> pList, pPreviousList = nullptr;
		while (getline(sstr, strPart, ','))
		{
			pList = std::make_shared<ListNode>(ListNode(stoi(strPart)));

			if (pPreviousList == nullptr)
			{
				pPreviousList = pList;
				head = pList;
				continue;
			}

			pPreviousList->next = pList;
			pPreviousList = pList;
		}

		return head;
	}
};


class Solution
{
	static constexpr uint64_t MAX_NODES_VALUE{100};

public:
	static ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
	{
		std::vector<uint64_t> vfirstNumber, vsecondNumber;
		for (size_t i = 0; i < Solution::MAX_NODES_VALUE and not (l1 == nullptr or l2 == nullptr); ++i)
		{
			vfirstNumber.insert(vfirstNumber.begin(), l1->val);
			l1 = l1->next.get();
			vsecondNumber.insert(vsecondNumber.begin(), l2->val);
			l2 = l2->next.get();
		}

		uint64_t firstNumber, secondNumber;
		firstNumber = secondNumber = 0;

		for (size_t i = 0; i < std::max(vfirstNumber.size(), vsecondNumber.size()); ++i)
		{
			if (i > vfirstNumber.size())
				firstNumber += pow(10, i);
			else
				firstNumber += vfirstNumber[i] * pow(10, i);

			if (i > vsecondNumber.size())
				secondNumber += pow(10, i);
			else
				secondNumber += vsecondNumber[i] * pow(10, i);
		}
		
		return new ListNode(firstNumber + secondNumber);
	}
};

int main()
{
	std::string firstList, secondList;

	// std::getline(std::cin, firstList);
	// std::getline(std::cin, secondList);
	firstList = "[2,3,4]";
	secondList = "[5,6,4]";

	std::shared_ptr<ListNode> l1 = ListNode::stringToList(firstList);
	std::shared_ptr<ListNode> l2 = ListNode::stringToList(secondList);

	std::cout << Solution::addTwoNumbers(l1.get(), l2.get())->val << std::endl;;


	return 0;
}

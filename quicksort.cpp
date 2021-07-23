//
// Created by Dan on 7/22/2021.
//

#include <list>
#include <algorithm>

std::list<int> sequential_quick_sort(std::list<int> input)
{
	//recursive condition
	if ( input.size() < 2 )
	{
		return input;
	}
	//move first element in the list to result list and take it as pivot value
	std::list<int> result;
	// splice in the form below only transfers a single element.  Note that transfer removes the element from the
	// first list.
	result.splice(result.begin(), input, input.begin());
	int pivot = *result.begin();

	//partition the input array so that t< pivot in lower part and t> pivot in upper part of input list
	auto divide_point = std::partition(input.begin(), input.end(),
		[&](int const& t)
		{
			return t < pivot;
		});

	//move lower part of the list to separate list so that we can make recursive call
	std::list<int> lower_list;
	lower_list.splice(lower_list.end(), input, input.begin(), divide_point);

	//call the sequential_quick_sort recursively
	auto new_lower(sequential_quick_sort(std::move(lower_list)));
	auto new_upper(sequential_quick_sort(std::move(input)));

	//transfer all elements in to result list
	result.splice(result.begin(), new_lower);
	result.splice(result.end(), new_upper);

	return result;
}
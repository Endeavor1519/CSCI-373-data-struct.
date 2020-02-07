#pragma once
//Robert M Dapice 02/07/2020

#ifndef MAIN_SAVITCH_NODE1_H
#define MAIN_SAVITCH_NODE1_H
#include <cstdlib> // Provides size_t and NULL


namespace main_savitch_5
{
	template<typename DataType>
	class node
	{
	public:
		// TYPEDEF
		typedef double DataType;

		// CONSTRUCTOR
		node(
			const DataType& init_data = DataType(),
			node* init_link = NULL
		)
		{
			data_field = init_data; link_field = init_link;
		}

		// Member functions to set the data and link fields:
		void set_data(const DataType& new_data) { data_field = new_data; }
		void set_link(node* new_link) { link_field = new_link; }

		// Constant member function to retrieve the current data:
		DataType data() const { return data_field; }

		// Two slightly different member functions to retreive
		// the current link:
		const node* link() const { return link_field; }
		node* link() { return link_field; }

	private:
		DataType data_field;
		node* link_field;
	};

	/*FUNCTIONS for the linked list toolkit
	std::size_t list_length(const node<DataType>* head_ptr);
	void list_head_insert(node*& head_ptr, const node::DataType& entry);
	void list_insert(node* previous_ptr, const node::DataType& entry);
	node* list_search(node* head_ptr, const node::DataType& target);
	const node* list_search
	(const node* head_ptr, const node::DataType& target);
	node* list_locate(node* head_ptr, std::size_t position);
	const node* list_locate(const node* head_ptr, std::size_t position);
	void list_head_remove(node*& head_ptr);
	void list_remove(node* previous_ptr);
	void list_clear(node*& head_ptr);
	void list_copy(const node* source_ptr, node*& head_ptr, node*& tail_ptr);
	//std::size_t list_occurrences(const node* head_ptr, const node::DataType& target);
	//void list_tail_attach(node*& head_ptr, const node::DataType& entry);
	//void list_tail_remove(node*& head_ptr);
	//node* list_copy_front(const node* source_ptr, std::size_t n);
	*/
}

#pragma once

namespace main_savitch_5
{
	template<typename DataType>
	size_t list_length(const node<DataType>* head_ptr)
		// Library facilities used: cstdlib
	{
		const node<DataType> *cursor;
		size_t answer;

		answer = 0;
		for (cursor = head_ptr; cursor != NULL; cursor = cursor->link())
			++answer;

		return answer;
	}

	template<typename DataType>
	void list_head_insert(node<DataType>*& head_ptr, const node<DataType>& entry)
	{
		head_ptr = new node<DataType>(entry, head_ptr);
	}

	template<typename DataType>
	void list_insert(node<DataType>* previous_ptr, const node<DataType>& entry)
	{
		node<DataType> *insert_ptr;

		insert_ptr = new node<DataType>(entry, previous_ptr->link());
		previous_ptr->set_link(insert_ptr);
	}

	template<typename DataType>
	node<DataType>* list_search(node<DataType>* head_ptr, const node<DataType>& target)
		// Library facilities used: cstdlib
	{
		node<DataType> *cursor;

		for (cursor = head_ptr; cursor != NULL; cursor = cursor->link())
			if (target == cursor->data())
				return cursor;
		return NULL;
	}

	template<typename DataType>
	const node<DataType>* list_search(const node<DataType>* head_ptr, const node<DataType>& target)
		// Library facilities used: cstdlib
	{
		const node<DataType> *cursor;

		for (cursor = head_ptr; cursor != NULL; cursor = cursor->link())
			if (target == cursor->data())
				return cursor;
		return NULL;
	}

	template<typename DataType>
	node<DataType>* list_locate(node<DataType>* head_ptr, size_t position)
		// Library facilities used: cassert, cstdlib
	{
		node<DataType> *cursor;
		size_t i;

		//assert(0 < position);
		cursor = head_ptr;
		for (i = 1; (i < position) && (cursor != NULL); i++)
			cursor = cursor->link();
		return cursor;
	}

	template<typename DataType>
	const node<DataType>* list_locate(const node<DataType>* head_ptr, size_t position)
		// Library facilities used: cassert, cstdlib
	{
		const node<DataType> *cursor;
		size_t i;

		//assert(0 < position);
		cursor = head_ptr;
		for (i = 1; (i < position) && (cursor != NULL); i++)
			cursor = cursor->link();
		return cursor;
	}

	template<typename DataType>
	void list_head_remove(node<DataType>*& head_ptr)
	{
		node<DataType> *remove_ptr;

		remove_ptr = head_ptr;
		head_ptr = head_ptr->link();
		delete remove_ptr;
	}

	template<typename DataType>
	void list_remove(node<DataType>* previous_ptr)
	{
		node<DataType> *remove_ptr;

		remove_ptr = previous_ptr->link();
		previous_ptr->set_link(remove_ptr->link());
		delete remove_ptr;
	}

	template<typename DataType>
	void list_clear(node<DataType>*& head_ptr)
		// Library facilities used: cstdlib
	{
		while (head_ptr != NULL)
			list_head_remove(head_ptr);
	}

	template<typename DataType>
	void list_copy(const node<DataType>* source_ptr, node<DataType>*& head_ptr, node<DataType>*& tail_ptr)
		// Library facilities used: cstdlib
	{
		head_ptr = NULL;
		tail_ptr = NULL;

		// Handle the case of the empty list.
		if (source_ptr == NULL)
			return;

		// Make the head node for the newly created list, and put data in it.
		list_head_insert(head_ptr, source_ptr->data());
		tail_ptr = head_ptr;

		// Copy the rest of the nodes one at a time, adding at the tail of new list.
		source_ptr = source_ptr->link();
		while (source_ptr != NULL)
		{
			list_insert(tail_ptr, source_ptr->data());
			tail_ptr = tail_ptr->link();
			source_ptr = source_ptr->link();
		}
	}


};


#endif

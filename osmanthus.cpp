#include <iostream>
#include <stdlib.h>

using namespace std;

class Node
{
   public:
      string data;
      Node *next;
      Node *previous;
      bool hasLeaf;
      int height;
};

class OsmanthusTreeDoubleLinkedList
{
   public:
      int length;
      int numberOfLevelsOfBranches;
      Node *head;
      Node *tail;
      void add_Stack(string data);
      void add_Queue(string data);
      void display();

      OsmanthusTreeDoubleLinkedList(int numberOfLevelsOfBranchesIN)
      {
         this->length = 0;
         this->numberOfLevelsOfBranches = numberOfLevelsOfBranchesIN;
         this->head = NULL;
         this->tail = NULL;
      }

      ~OsmanthusTreeDoubleLinkedList()
      {
         cout << "List Destroyed." << endl;
      }
};


void OsmanthusTreeDoubleLinkedList::add_Stack(string data)
{
   Node *node = new Node();
   node->data = data;
   node->next = NULL;
   node->hasLeaf = false;

   if(data.find(to_string(this->numberOfLevelsOfBranches)) != std::string::npos)
   {
      node->hasLeaf = true;
   }

   if(tail != NULL)
   {
      node->previous = tail;
      tail->next = node;
   }
   else
   {
      head = node;
      node->previous = NULL;
   }
   tail = node;
   node->height = rand() % 30 + 1;
   length++;
}

void OsmanthusTreeDoubleLinkedList::add_Queue(string data)
{
   Node *node = new Node();
   node->data = data;
   node->previous = NULL;
   node->hasLeaf = false;

   if(data.find(to_string(this->numberOfLevelsOfBranches)) != std::string::npos)
   {
      node->hasLeaf = true;
   }

   if(head != NULL)
   {
      node->next = head;
      head->previous = node;
   }
   else
   {
      node->next = NULL;
      tail = node;
   }
   head = node;
   node->height = rand() % 30 + 1;
   length++;
}

void OsmanthusTreeDoubleLinkedList::display()
{
   Node *revealNode = head;

   if(length == 0)
      return;
   else if(revealNode == NULL)
   {
      cout << "Empty list." << endl;
      return;
   }

   while(revealNode != NULL)
   {
      if(revealNode->hasLeaf)
      {
         cout << revealNode->data << " ***Flowers here***!" << endl;
      }
      else
      {
         cout << revealNode->data << " No flowers here!" << endl;
      }
      revealNode = revealNode->next;
   }
}

int main()
{
   OsmanthusTreeDoubleLinkedList *linkedList = new OsmanthusTreeDoubleLinkedList(5);


   linkedList->add_Stack("Trunk");
   linkedList->add_Stack("1 Right");
   linkedList->add_Stack("2 Right Left");
   linkedList->add_Stack("2 Right Right");
   linkedList->add_Stack("3 Right Left Left");
   linkedList->add_Stack("3 Right Left Right");
   linkedList->add_Stack("3 Right Right Left");
   linkedList->add_Stack("3 Right Right Right");
   linkedList->add_Stack("4 Right Left Left Left");
   linkedList->add_Stack("4 Right Left Left Right");
   linkedList->add_Stack("4 Right Left Right Left");
   linkedList->add_Stack("4 Right Left Right Right");
   linkedList->add_Stack("4 Right Right Left Left");
   linkedList->add_Stack("4 Right Right Left Right");
   linkedList->add_Stack("4 Right Right Right Left");
   linkedList->add_Stack("4 Right Right Right Right");
   linkedList->add_Stack("5 Right Left Left Left Left");
   linkedList->add_Stack("5 Right Left Left Left Right");
   linkedList->add_Stack("5 Right Left Left Right Left");
   linkedList->add_Stack("5 Right Left Left Right Right");
   linkedList->add_Stack("5 Right Left Right Left Left");
   linkedList->add_Stack("5 Right Left Right Left Right");
   linkedList->add_Stack("5 Right Left Right Right Left");
   linkedList->add_Stack("5 Right Left Right Right Right");
   linkedList->add_Stack("5 Right Right Left Left Left");
   linkedList->add_Stack("5 Right Right Left Left Right");
   linkedList->add_Stack("5 Right Right Left Right Left");
   linkedList->add_Stack("5 Right Right Left Right Right");
   linkedList->add_Stack("5 Right Right Right Left Left");
   linkedList->add_Stack("5 Right Right Right Left Right");
   linkedList->add_Stack("5 Right Right Right Right Left");
   linkedList->add_Stack("5 Right Right Right Right Right");

   linkedList->add_Queue("1 Left");
   linkedList->add_Queue("2 Left Left");
   linkedList->add_Queue("2 Left Right");
   linkedList->add_Queue("3 Left Left Left");
   linkedList->add_Queue("3 Left Left Right");
   linkedList->add_Queue("3 Left Right Left");
   linkedList->add_Queue("3 Left Right Right");
   linkedList->add_Queue("4 Left Left Left Left");
   linkedList->add_Queue("4 Left Left Left Right");
   linkedList->add_Queue("4 Left Left Right Left");
   linkedList->add_Queue("4 Left Left Right Right");
   linkedList->add_Queue("4 Left Right Left Left");
   linkedList->add_Queue("4 Left Right Left Right");
   linkedList->add_Queue("4 Left Right Right Left");
   linkedList->add_Queue("4 Left Right Right Right");
   linkedList->add_Queue("5 Left Left Left Left Left");
   linkedList->add_Queue("5 Left Left Left Left Right");
   linkedList->add_Queue("5 Left Left Left Right Left");
   linkedList->add_Queue("5 Left Left Left Right Right");
   linkedList->add_Queue("5 Left Left Right Left Left");
   linkedList->add_Queue("5 Left Left Right Left Right");
   linkedList->add_Queue("5 Left Left Right Right Left");
   linkedList->add_Queue("5 Left Left Right Right Right");
   linkedList->add_Queue("5 Left Right Left Left Left");
   linkedList->add_Queue("5 Left Right Left Left Right");
   linkedList->add_Queue("5 Left Right Left Right Left");
   linkedList->add_Queue("5 Left Right Left Right Right");
   linkedList->add_Queue("5 Left Right Right Left Left");
   linkedList->add_Queue("5 Left Right Right Left Right");
   linkedList->add_Queue("5 Left Right Right Right Left");
   linkedList->add_Queue("5 Left Right Right Right Right");

   linkedList->display();

   return 0;
}

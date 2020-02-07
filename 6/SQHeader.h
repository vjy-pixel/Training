/**************************************************
	* iFront - The foremost element of the Queue.
	* iRear - The last element of the Queue.
***************************************************/
int iFront=-1,iRear=-1;

/************************************************
	* iHead - The topmost element of the Stack.
*************************************************/
int iHead = -1;

/****************************************
	* iSize - size of the Queue or Stack.
*****************************************/
int iSize;

/**********************************************************************
	* This method will insert an element at the last position
	*
	* of the Queue, that will be passed as an argument to the method.
	*
	* @param *ptrArray, iElement
	*
	* @return void
**********************************************************************/
void Enqueue(int*, int);

/****************************************************************************
	* This method will take the foremost element of the Queue and
	*
	* will place it at the last position as here circular queue is performed.
	*
	* @param *ptrArray
	*
	* @return void
*****************************************************************************/
void Dequeue(int*);

/*****************************************************************************
	* This method will take the foremost element of the Queue This method will
	*
	* be used when deletion of the element from the queue is required. 
	*
	* @param *ptrArray
	*
	* @return void
*****************************************************************************/
void ForcedDequeue(int*);


/*****************************************************************************
	* This method will give the View to the current of the Queue or the Stack.
	*
	* @param *ptrArray
	*
	* @return void
******************************************************************************/
void View(int*);


/**********************************************************************
	* This method will insert an element at the topmost position
	*
	* of the Stack, that will be passed as an argument to the method.
	*
	* @param *ptrArray, iElement
	*
	* @return void
**********************************************************************/
void Push(int*, int);


/**********************************************************************
	* This method will delete an element from the topmost position
	*
	* of the Stack
	*
	* @param *ptrArray
	*
	* @return void
**********************************************************************/
void Pop(int*);

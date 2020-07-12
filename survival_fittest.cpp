//Geeks SDET-5 very important question.
// In a class of N students where each student has some weight Wi, are going to have an activity in which they are going to make groups. To make a group, students are standing in a queue and there are some rules to follow:
//        1. Each student in the queue having weight Wi can be grouped with student after him with weight Wj.
//        2. There must be more number of students in the class with weight Wj than that of Wi to group with students of weight Wj.
// void fittestClass(int arr[], int n)

// Input:
// 1
// 8
// 18 17 34 21 18 17 18 21

// Output:
// -1 18 21 18 -1 18 -1 -1
void fittestClass(int arr[], int n)
{
    int max = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] > max)
          max = arr[i];
    }
    
    int freq[max+1] = {0};
    
    for(int i = 0; i < n; i++)
     freq[arr[i]]++;
     
    
    stack<int> s;
    s.push(0);
    int res[n] = {0};
    for(int i = 1; i < n; i++)
    {

        if (!s.empty() && freq[arr[s.top()]] > freq[arr[i]])
            s.push(i);
        else
        {

            while (!s.empty() && freq[arr[s.top()]] < freq[arr[i]])
            {

                res[s.top()] = arr[i];
                s.pop();
            }

            s.push(i);
        }
    }
    
    while (!s.empty()) 
    { 
        res[s.top()] = -1; 
        s.pop(); 
    } 
    for (int i = 0; i < n; i++) 
    { 
        // Print the res list containing next  
        // greater frequency element 
        cout << res[i] << " "; 
    } 
}
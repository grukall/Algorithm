#include <iostream>
#include <algorithm>

using namespace std;

class heap
{
    private:
        int size;
        int csz;
        int *v;

        void heapify();
        bool comp(int ai, int bi);

    public:
        heap();
        ~heap();

        void push(int n);
        int top();
        void pop();
        int num();
        bool empty();
        void printHeap();

};

void heap::heapify()
{
    int curi = 0;
    while (true)
    {
        int left = curi*2+1;
        int right = curi*2+2;

        if (left >= size) break;
        else if (right >= size)
        {
            if (comp(v[left], v[curi]))
            {
              //  printf("v[%d] %d < v[%d] %d\n", left, v[left], curi, v[curi]);
                swap(v[left], v[curi]);
            }
            
            break;
        }
        else if (comp(v[left], v[curi]) && comp(v[right], v[curi]))
        {
            if (comp(v[left], v[right]))
            {
              //  printf("v[%d] %d > v[%d] %d\n", left, v[left], right, v[right]);
                swap(v[left], v[curi]);
                curi = left;
            }
            else
            {
             //   printf("v[%d] %d <= v[%d] %d\n", left, v[left], right, v[right]);
                swap(v[right], v[curi]);
                curi = right;
            }
        }
        else if (comp(v[left], v[curi]))
        {
          //  printf("v[%d] %d < v[%d] %d\n", left, v[left], curi, v[curi]);
            swap(v[left], v[curi]);
            curi = left;
        }
        else if (comp(v[right], v[curi]))
        {
           // printf("v[%d] %d < v[%d] %d\n", right, v[right], curi, v[curi]);
            swap(v[right], v[curi]);
            curi = right;
        }
        else break;
    }
}

bool heap::comp(int ai, int bi)
{
    if (abs(ai) < abs(bi))
        return true;
    else if (abs(ai) > abs(bi))
        return false;
    else
    {
        if (ai < bi)
            return true;
        else if (ai > bi)
            return false;
        else
            return false;
    }
}


heap::heap()
{
    v = new int[1];
    csz = 1;
    size = 0;
}

heap::~heap()
{
    free(v);
}

void heap::push(int n)
{
    if (size == csz)
    {
        //1+2+4...
        csz = csz + csz*2;
        int *newv = new int[csz];
        for (int i = 0; i < size; i++)
            newv[i] = v[i];
        
        free(v);
        v = newv;

    }

    v[size] = n;
    int curi = size;
    while (curi > 0)
    {
        int parenti;
        if (curi % 2 == 1)
            parenti = curi/2;
        else
            parenti = curi/2 - 1;
        
        if (comp(v[curi], v[parenti]))
        {
           // printf("v[%d] %d < v[%d] %d\n", curi, v[curi], parenti, v[parenti]);
            swap(v[curi], v[parenti]);
            curi = parenti;
        }
        else break;
    }
    size += 1;
}

int heap::top()
{
    if (size > 0)
        return v[0];
    
    return 0;
}

void heap::pop()
{
    if (size > 0)
    {
        size -= 1;
        v[0] = v[size];
        heapify();
    }
}

int heap::num()
{
    return size;
}

bool heap::empty()
{
    return size == 0;
}

void heap::printHeap()
{
    printf("[");
    for (int i = 0; i < size-1; i++)
    {
        printf("%d ", v[i]);
    }
    printf("%d]\n", v[size-1]);
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    heap pq;
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num; cin >> num;
        if (num == 0)
        {
            if (pq.empty())
                cout << '0' << '\n';
            else
            {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else
        {
            pq.push(num);
        }
     //   pq.printHeap();
    }
}
void group_divide(const std::vector<int>& vector, std::vector<std::pair<int, int> >& pairs)
{
    for (size_t i = 0; i < vector.size() - 1; i += 2)
	{
        if (vector[i] > vector[i + 1])
        	pairs.push_back(std::make_pair(vector[i + 1], vector[i])); // step 2, swap order if left element is bigger than right element
        else
        	pairs.push_back(std::make_pair(vector[i], vector[i + 1]));
    }
}

void mergePairs(std::vector<std::pair<int, int> >& pairs, int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;

    std::vector<std::pair<int, int> > left(n1), right(n2);
    for (int i = 0; i < n1; i++)
        left[i] = pairs[low + i];
    for (int j = 0; j < n2; j++)
        right[j] = pairs[mid + 1 + j];

    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2)
	{
        if (left[i].second <= right[j].second)
        	pairs[k++] = left[i++];
        else
        	pairs[k++] = right[j++];
        
    }
    while (i < n1)
        pairs[k++] = left[i++];
    while (j < n2)
        pairs[k++] = right[j++];
}

void recursiveSort(std::vector<std::pair<int, int> >& pairs, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;

        recursiveSort(pairs, low, mid);
        recursiveSort(pairs, mid + 1, high);
        mergePairs(pairs, low, mid, high);
    }
}

void    binary_insert(std::vector<int>& mainChain, std::vector<int>& pend)
{
    size_t  currentPendIndex = 0, currentMainIndex = 0;
    size_t  jacobsthal_diff[] = { //https://oeis.org/A078008
        2, 2, 6, 10, 22, 42, 86, 170, 342, 682, 1366,
        2730, 5462, 10922, 21846, 43690, 87382, 174762, 349526, 699050,
        1398102, 2796202, 5592406, 11184810, 22369622, 44739242, 89478486,
        178956970, 357913942, 715827882, 1431655766};
    
    for (int k = 0;; ++k)
    {
        if (jacobsthal_diff[k] > pend.size() - currentPendIndex)
            break;
        for (size_t offset = 0; offset < jacobsthal_diff[k]; ++offset)
        {
            int pendulumElement = pend[currentPendIndex + offset];
            int insertPos = std::upper_bound(mainChain.begin(), mainChain.begin() + currentMainIndex + offset + 1, pendulumElement) - mainChain.begin(); //std::upper_bound is binary search https://eklitzke.org/std-upper-bound-and-std-lower-bound
            mainChain.insert(mainChain.begin() + insertPos, pendulumElement);
        }
        currentPendIndex += jacobsthal_diff[k];
        currentMainIndex += 2 * jacobsthal_diff[k];
    }
    while (currentPendIndex < pend.size())
    {
        int pendulumElement = pend[currentPendIndex];
        int insertPos = std::upper_bound(mainChain.begin(), mainChain.end(), pendulumElement) - mainChain.begin(); // Search entire mainChain
        mainChain.insert(mainChain.begin() + insertPos, pendulumElement);
        currentPendIndex++;
    }
}

void ford_johnson(std::vector<int>& data)
{
    //need to check memory
    std::vector<std::pair<int, int> > pairs;
    std::vector<int> mainChain, pend;

    group_divide(data, pairs); // Step 1 & 2: Group and divide into pairs
    recursiveSort(pairs, 0, pairs.size() - 1); // Step 3: Recursively sort by 'big' values

    for (size_t i = 0; i < pairs.size(); ++i)
    {
        mainChain.push_back(pairs[i].second);
        pend.push_back(pairs[i].first);
    }
    if(data.size() % 2 != 0)    //if the number of elements is odd, we add the last one to the end of pend, ensuring it's placed correctly no matter the value
        pend.push_back(data.back());
    binary_insert(mainChain, pend); //step 4 & 5: Binary insert 'small' elements
    data = mainChain;
}

//////////////////////

void group_divide(const std::deque<int>& deque, std::deque<std::pair<int, int> >& pairs) {
    for (size_t i = 0; i < deque.size() - 1; i += 2)
	{
        if (deque[i] > deque[i + 1])
        	pairs.push_back(std::make_pair(deque[i + 1], deque[i])); // step 2, swap order if left element is bigger than right element
        else
        	pairs.push_back(std::make_pair(deque[i], deque[i + 1]));
    }
}

void mergePairs(std::deque<std::pair<int, int> >& pairs, int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;

    std::deque<std::pair<int, int> > left(n1), right(n2);
    for (int i = 0; i < n1; i++)
        left[i] = pairs[low + i];
    for (int j = 0; j < n2; j++)
        right[j] = pairs[mid + 1 + j];

    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2)
	{
        if (left[i].second <= right[j].second)
        	pairs[k++] = left[i++];
        else
        	pairs[k++] = right[j++];
        
    }
    while (i < n1)
        pairs[k++] = left[i++];
    while (j < n2)
        pairs[k++] = right[j++];
}

void recursiveSort(std::deque<std::pair<int, int> >& pairs, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;

        recursiveSort(pairs, low, mid);
        recursiveSort(pairs, mid + 1, high);
        mergePairs(pairs, low, mid, high);
    }
}

void    binary_insert(std::deque<int>& mainChain, std::deque<int>& pend)
{
    size_t  currentPendIndex = 0, currentMainIndex = 0;
    size_t  jacobsthal_diff[] = { //https://oeis.org/A078008
        2, 2, 6, 10, 22, 42, 86, 170, 342, 682, 1366,
        2730, 5462, 10922, 21846, 43690, 87382, 174762, 349526, 699050,
        1398102, 2796202, 5592406, 11184810, 22369622, 44739242, 89478486,
        178956970, 357913942, 715827882, 1431655766};
    
    for (int k = 0;; ++k)
    {
        if (jacobsthal_diff[k] > pend.size() - currentPendIndex)
            break;
        for (size_t offset = 0; offset < jacobsthal_diff[k]; ++offset)
        {
            int pendulumElement = pend[currentPendIndex + offset];
            int insertPos = std::upper_bound(mainChain.begin(), mainChain.begin() + currentMainIndex + offset + 1, pendulumElement) - mainChain.begin(); //std::upper_bound is binary search https://eklitzke.org/std-upper-bound-and-std-lower-bound
            mainChain.insert(mainChain.begin() + insertPos, pendulumElement);
        }
        currentPendIndex += jacobsthal_diff[k];
        currentMainIndex += 2 * jacobsthal_diff[k];
    }
    while (currentPendIndex < pend.size())
    {
        int pendulumElement = pend[currentPendIndex];
        int insertPos = std::upper_bound(mainChain.begin(), mainChain.end(), pendulumElement) - mainChain.begin(); // Search entire mainChain
        mainChain.insert(mainChain.begin() + insertPos, pendulumElement);
        currentPendIndex++;
    }
}

void ford_johnson(std::deque<int>& data) {
    std::deque<std::pair<int, int> > pairs;
    std::deque<int> mainChain, pend;

    group_divide(data, pairs);
    recursiveSort(pairs, 0, std::distance(pairs.begin(), pairs.end()) - 1); 
    
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        mainChain.push_back(pairs[i].second);
        pend.push_back(pairs[i].first);
    }
    if(data.size() % 2 != 0)    //if the number of elements is odd, we add the last one to the end of pend, ensuring it's placed correctly no matter the value
        pend.push_back(data.back());
    binary_insert(mainChain, pend); //step 4 & 5: Binary insert 'small' elements
    data = mainChain;   
}

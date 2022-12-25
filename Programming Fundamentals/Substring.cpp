int findSubString(char arr[], char sub[], int index)		//return index if substring found else -1
{
	for (index; arr[index] != '\0'; index++)	
		if (arr[index] == sub[0]) {
			int i = index, j = 0;
			for (; sub[j] != '\0' && arr[i] != '\0' && arr[i] == sub[j]; j++, i++);
			if (j == strlen(sub))
				return index;
		}
	return -1;
}

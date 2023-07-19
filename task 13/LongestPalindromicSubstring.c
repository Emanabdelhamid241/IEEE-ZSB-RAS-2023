int largestPalindrome(char *s){
	int n = strlen(s);

	int maxLen = 1, start = 0;

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			int flag = 1;

			for (int k = 0; k < (j - i + 1) / 2; k++)
				if (s[i + k] != s[j - k])
					flag = 0;

			//if  Palindrome
			if (flag && (j - i + 1) > maxLen) {
				start = i;
				maxLen = j - i + 1;
			}
		}
	}



	return maxLen;


}

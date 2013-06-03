#include <iostream>
#include <fstream>
using namespace std;


int max(int a, int b)
{
	return (a > b) ? a : b;
}

int min(int a, int b)
{
	return (a < b) ? a : b;
}

int main()
{
	ifstream fin ("packrec.in");
	ofstream fout ("packrec.out");

	int l[4], b[4];
	int minArea, maxLength, maxBreadth, area1, area2, len, bre, trNuml, trNumb, len1, bre1, minl, minb, m, maxLen, maxBre;
	int area[7], flength[7], fbreadth[7];
	int i, j, k;
	bool flagl, flagb;

	//fin >> l1 >> b1 >> l2 >> b2;
	//fin >> l3 >> b3 >> l4 >> b4;
	for(i = 0; i < 4; i++)
	{
		fin >> l[i] >> b[i];
	}

	// 1st rectangle
	maxLength = max(l[0], max(l[1], max(l[2], l[3])));
	maxBreadth = max(b[0], max(b[1], max(b[2], b[3])));

	area1 = maxLength * (b[0] + b[1] + b[1] + b[1]);
	area2 = maxBreadth * (l[0] + l[1] + l[2] + l[3]);

	// min possible area for first configuration
	// 1st possibility
	if(area1 < area2)
	{
		area[1] = area1;
		flength[1] = maxLength;
		fbreadth[1] = b[0] + b[1] + b[2] + b[3];
	}
	else
	{
		area[1] = area2;
		flength[1] = l[0] + l[1] + l[2] + l[3];
		fbreadth[1] = maxBreadth;
	}
	
	// 2nd possibility
	len = 0;
	bre = 0;

	for(i = 0; i < 4; i++)
	{
		len += l[i];
		bre += b[i];
	}
	
	area[2] = 16*50*50;
	for(i = 0; i < 4; i++)
	{
		
		len = len - l[i];
		bre = bre - b[i];
		maxBre = 0;
		maxLen = 0;
		for(j = 0; j < 4; j++)
		{
			if(j != i && maxBre < b[j])
			{
				maxBre = b[j];
			}
			if(j != i && maxLen < l[j])
			{
				maxLen = l[j];
			}
		}

		area1 = max(len, b[i]) * (maxBre + l[i]);
		area2 = max(bre, l[i]) * (maxLen + b[i]);

		// min area
		if(area[2] > area1)
		{
			area[2] = area1;
			flength[2] = max(len, b[i]);
			fbreadth[2] = maxBre + l[i];
		}

		if(area[2] > area2)
		{
			area[2] = area2;
			flength[2] = maxLen + b[i];
			fbreadth[2] = max(bre, l[i]);
		}

		len += l[i];
		bre += b[i];
	}
	
	// 3rd possibility
	area[3] = 16*50*50;
	/*
	for(i = 0; i < 4; i++)
	{
		for(j = 0; j < 4; j++)
		{
			if(j != i && maxBre < b[j])
			{
				maxBre = b[j];
				trNumb = j;
			}
			if(j != i && maxLen < l[j])
			{

				maxLen = l[j];
				trNuml = j;
			}
		}
		area1 = maxBre * (b[i] + l[trNumb]);
		area2 = maxLen * (l[i] + b[trNuml]);
		
		// minimum area
		if(area[2] > area1)
		{
			area[2] = area1;
			flength[2] = b[i] + l[trNumb];
			fbreadth[2] = maxBre;
		}
		if(area[2] > area2)
		{
			area[3] = area2;
			flength[3] = maxLen;
			fbreadth[3] = l[i] + b[trNuml];
		}
	}
	*/
	for(i = 0; i < 4; i++)
	{
		for(j = 0; j < 4; j++)
		{
			if(i != j)
			{
				for(k = 0; k < 4; k++)
				{
					if(k != i && k != j)
					{
						for(m = 0; m < 4; m++)
						{
							if(m != i && m != j && m != k)
							{
								bre1 = max(l[j], max(b[i] + l[k], b[i] + l[m]));
								len1 = max(b[j], max(l[i] + b[k], l[i] + b[m]));

								area1 = bre1 * (max(l[i], b[k] + b[m]) + b[j]);
								area2 = len1 * (max(b[i], l[k] + l[m]) + l[j]);
								if(area[3] > area1)
								{
									area[3] = area1;
									flength[3] = min(bre1, max(l[i], b[k] + b[m]) + b[j]);
									fbreadth[3] = max(bre1, max(l[i], b[k] + b[m]) + b[j]);
								}
								if(area[3] > area2)
								{
									area[3] = area2;
									flength[3] = min(len1, max(b[i], l[k] + l[m]) + l[j]);
									fbreadth[3] = max(len1, max(b[i], l[k] + l[m]) + l[j]);
								}
							}
						}
					}
				}
			}
		}
	}

	//4th possibility
	area[4] = 16 * 50 * 50;
	len = 0;
	bre = 0;
	for(i = 0; i < 4; i++)
	{
		len += l[i];
		bre += b[i];
	}

	for(i = 0; i < 4; i++)
	{
		for(j = 0; j < 4; j++)
		{
			if(j != i)
			{
				len1 = l[i] + l[j];
				bre1 = b[i] + b[j];
			
				bre = bre - b[i] - b[j] + max(b[i], b[j]);
				len = len - l[i] - l[j] + max(l[i], l[j]);

				area1 = max(len1, max(l[0], max(l[1], max(l[2], l[3])))) * bre;
				area2 = max(bre1, max(b[0], max(b[1], max(b[2], b[3])))) * len;

				if(area[4] > area1)
				{
					area[4] = area1;
					flength[4] = max(len1, max(l[0], max(l[1], max(l[2], l[3]))));
					fbreadth[4] = bre;
				}
				if(area[4] > area2)
				{
					area[4] = area2;
					flength[4] = max(bre1, max(b[0], max(b[1], max(b[2], b[3]))));
					fbreadth[4] = len;
				}
				len = len + l[i] + l[j] - max(l[i], l[j]);
				bre = bre + b[i] + b[j] - max(b[i], b[j]);
			}
		}
	}

	// 5th possibility
	area[5] = 16 * 50 * 50;
	len = 0;
	bre = 0;
	for(i = 0; i < 4; i++)
	{
		len += l[i];
		bre += b[i];
	}

	for(i = 0; i < 4; i++)
	{
		for(j = 0; j < 4; j++)
		{
			if(j != i)
			{
				len1 = l[i] + l[j];
				bre1 = b[i] + b[j];
				
				bre = bre - b[i] - b[j] + max(b[i], b[j]);
				len = len - l[i] - l[j] + max(l[i], l[j]);
				minl = 51;
				minb = 51;
				for(k = 0; k < 4; k++)
				{
					if(k != i && k != j && l[k] >= len1)
					{
						if(minl > l[k])
						{
							minl = l[k];
							trNuml = k;
						}
						flagl = true;	
					}

					if(k != i && k != j && b[k] >= bre1)
					{
						if(minb > b[k])
						{
							minb = b[k];
							trNumb = k;
						}
					}
					flagb = true;
				}

				if(flagl)
				{
					area1 = l[trNuml] * bre;
				}
				else
				{
					area1 = len1 * bre;
				}

				if(flagb)
				{
					area2 = b[trNumb] * len;
				}
				else
				{
					area2 = bre1 * len;
				}
				
				if(area[5] > area1)
				{
					area[5] = area1;
					
					flength[5] = flagl ? l[trNuml] : len1;
					fbreadth[5] = bre;
				}

				if(area[5] > area2)
				{
					area[5] = area2;

					flength[5] = len;
					fbreadth[5] = flagb? b[trNumb] : bre1;
				}

				len = len + l[i] + l[j] - max(l[i], l[j]);
				bre = bre + b[i] + b[j] - max(b[i], b[j]);
			}
		}
	}

	// 6th possibility

	area[6] = 16 * 50 * 50;
	
	len = 0;
	bre = 0;

	for(i = 0; i < 4; i++)
	{
		len += l[i];
		bre += b[i];
	}

	for(i = 0; i < 4; i++)
	{
		for(j = 0; j < 4; j++)
		{
			if(j != i)
			{
				len1 = max(b[i], l[j]);
				bre1 = max(l[i], b[j]);
				for(k = 0; k < 4; k++)
				{
					if(k != i && k != j)
					{
						for(m = 0; m < 4; m++)
						{
							if(m != i && m != j && m != k)
							{
								if(len1 + b[k] - min(b[i], l[j]) >= l[m])
								{
									area1 = (len1 + b[k]) * max(l[i] + b[j], l[k] + b[m]);
								}
								if(bre1 + b[k] - min(l[i], b[j]) >= b[m])
								{
									area2 = (bre1 + l[k]) * max(b[i] + l[j], b[k] + l[m]);
								}
								
								if(area[6] > area1)
								{
									area[6] = area1;
									flength[6] = max(len1 + b[k], max(l[i] + b[j], l[k] + b[m]));
									fbreadth[6] = min(len1 + b[k], max(l[i] + b[j], l[k] + b[m]));
								}
								if(area[6] > area2)
								{
									area[6] = area2;
									flength[6] = max(bre1 + l[k], max(b[i] + l[j], b[k] + l[m]));
									fbreadth[6] = min(bre1 + l[k], max(b[i] + l[j], b[k] + l[m]));
								}
							}
						}
					}
				}
			}
		}
	}

	// min calculation
	
	int finalA, finalL, finalB;

	finalA = 16 * 50 * 50;
	for(i = 1; i <= 6; i++)
	{
		if(finalA > area[i])
		{
			finalA = area[i];
			finalL = flength[i];
			finalB = fbreadth[i];
		}
		cout << i << " " << area[i] << " " << flength[i] << " " << fbreadth[i] << endl;	
	}

	cout << finalA << endl << finalL << " " << finalB << endl;

	fout << finalA << endl << finalL << " " << finalB << endl;

	
	return 0;
}

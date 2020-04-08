/*bool operator > (const Information& Info)
{
	unsigned int i = 0;
	bool flag = false;
	if (Year > Info.Year)
		flag = true;
	if (!flag)
		if (Year == Info.Year)
			while ((i < size(Name)) && (i < size(Info.Name)))
			{
				if (Name[i] < Info.Name[i])
				{
					flag = true;
					break;
				}
				i++;
			}
	return flag;
}
};*/
def main():
	n = input()
	row1 = raw_input()
	row2 = list()
	i = 0
	while i+1 <=(2*n-1):
		if row1[i]=='A' and row1[i+1]=='B' or row1[i]=='B' and row1[i+1]=='A' :
			if i==0 or row2[i-1]!='C':  
				row2.append('C'), row2.append('D')
			else:
				row2.append('D'), row2.append('C')
		elif row1[i]=='C' and row1[i+1]=='D' or row1[i]=='D' and row1[i+1]=='C' :
			if i==0 or row2[i-1]!='A': 
				row2.append('A'), row2.append('B')
			else:
				row2.append('B'), row2.append('A')
		elif row1[i]=='C' and row1[i+1]=='A' or row1[i]=='A' and row1[i+1]=='C' :
			if i==0 or row2[i-1]!='B': 
				row2.append('B'), row2.append('D')
			else:
				row2.append('D'), row2.append('B')
		elif row1[i]=='C' and row1[i+1]=='B' or row1[i]=='B' and row1[i+1]=='C' :
			if i==0 or row2[i-1]!='A': 
				row2.append('A'), row2.append('D')
			else:
				row2.append('D'), row2.append('A')
		elif row1[i]=='A' and row1[i+1]=='D' or row1[i]=='D' and row1[i+1]=='A' :
			if i==0 or row2[i-1]!='B': 
				row2.append('B'), row2.append('C')
			else:
				row2.append('C'), row2.append('B')
		elif row1[i]=='B' and row1[i+1]=='D' or row1[i]=='D' and row1[i+1]=='B' :	
			if i==0 or row2[i-1]!='A': 
				row2.append('A'), row2.append('C')
			else:
				row2.append('C'), row2.append('A')
		i+=2
	print "".join(row2)
 
 
main()
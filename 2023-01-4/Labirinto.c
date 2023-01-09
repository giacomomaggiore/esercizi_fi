#define N 4

int soluzione(int *p_matrice){
	int i,j,conta = 0;
	int flag[N][N];

	//Per capire dove posso andare mi aiuto con la matrice flag
	//Inizializzo flag a 0
	for(i = 0; i < N; i++)
		for(j = 0; j < N; j++)
			flag[i][j] = 0;
	//Tranne nella casella di partenza dove è 1
	flag[0][0] = 1;

	//uso conta per contare quanti step faccio, se dopo (N*N)-1 step non sono arrivato vuol dire che non c'è un percorso fattibile
	//(non sono sicuro di questa formula, ma a logica N*N sono tutte le caselle, -1 perchè la prima è quella su cui sei già)
	while(conta<=(N*N)-1) {
	//scorro lungo tutta la matrice
		for(i = 0; i < N; i++)
			for(j = 0; j < N; j++)
				//se il flag è 1 vedo se posso muovermi, in pratica se il valore assoluto della differenza tra caselle
				//adiacenti è 1 allora posso muovermi lì e quindi updato il flag
				//(controllo che siano adiacenti con l'aritmetica dei puntatori)
				if(flag[i][j] == 1){
					if(abs(*(p_matrice+N*i+j)-*(p_matrice+N*i+j+1)) == 1)
						flag[i][j+1] = 1;
					if(abs(*(p_matrice+N*i+j)-*(p_matrice+N*i+j-1)) == 1)
						flag[i][j-1] = 1;
					if(abs(*(p_matrice+N*i+j)-*(p_matrice+N*(i+1)+j)) == 1)
						flag[i+1][j] = 1;
					if(abs(*(p_matrice+N*i+j)-*(p_matrice+N*(i-1)+j)) == 1)
						flag[i-1][j] = 1;
				}
		conta++;
		//se la casella in fondo a destra ha flag = 1 allora ho finito
		if(flag[N-1][N-1] == 1)
			return 1;
	}
	return 0;
}
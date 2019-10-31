import java.util.*;
import java.lang.*;
import java.io.*;

public class Q2{
	static int a[];
	static  int segtreemin[];
	static int segtreemax[];
	static int segtreesum[];

	static void builtree(int start,int end,int index){
		if(start==end){
			segtreesum[index]=a[start];
			segtreemin[index]=a[start];
			segtreemax[index]=a[start];
			return;
		}
		int mid=(start+end)/2;
		builtree(start,mid,2*index);
		builtree(mid+1,end,2*index+1);
		segtreemax[index]=Math.max(segtreemax[2*index],segtreemax[2*index+1]);
		segtreemin[index]=Math.min(segtreemin[2*index],segtreemin[2*index+1]);
		segtreesum[index]=segtreesum[2*index]+segtreesum[2*index+1];
	}

	static int sumquery(int st,int ed,int qs,int qe,int index){
		if(ed<qs||st>qe){
			return 0;
		}
		else if(st>=qs&&ed<=qe){
			return segtreesum[index];
		}
		else{
			int mid=(st+ed)/2;
			int sum=0;
			sum+=sumquery(st,mid,qs,qe,2*index);
			sum+=sumquery(mid+1,ed,qs,qe,2*index+1);
			return sum;
		}
	}
	static int minquery(int st,int ed,int qs,int qe,int index){
		if(ed<qs||st>qe){
			return 1000000000;
		}
		else if(st>=qs&&ed<=qe){
			return segtreemin[index];
		}
		else{
			int mid=(st+ed)/2;
			int sum1=minquery(st,mid,qs,qe,2*index);
			int sum2=minquery(mid+1,ed,qs,qe,2*index+1);
			return Math.min(sum1,sum2);
		}
	}

	static int maxquery(int st,int ed,int qs,int qe,int index){
		if(ed<qs||st>qe){
			return -1000000000;
		}
		else if(st>=qs&&ed<=qe){
			return segtreemax[index];
		}
		else{
			int mid=(st+ed)/2;
			int sum1=maxquery(st,mid,qs,qe,2*index);
			int sum2=maxquery(mid+1,ed,qs,qe,2*index+1);
			return Math.max(sum1,sum2);
		}
	}

	static void update(int st,int ed,int qs,int qe,int index){
		if(st>qe||ed<qs){
			return;
		}
		if(st==ed){
			segtreesum[index]+=4;
			segtreemin[index]+=4;
			segtreemax[index]+=4;
			return;
		}
		int mid=(st+ed)/2;
		update(st,mid,qs,qe,2*index);
		update(mid+1,ed,qs,qe,2*index+1);
		segtreemax[index]=Math.max(segtreemax[2*index],segtreemax[2*index+1]);
		segtreemin[index]=Math.min(segtreemin[2*index],segtreemin[2*index+1]);
		segtreesum[index]=segtreesum[2*index]+segtreesum[2*index+1];
	}


    public static void main(String[] args) {
    	System.out.println("HELLO");
    	a=new int[10000];
		segtreemin=new int[10000];
		segtreemax=new int[10000];
		segtreesum=new int[10000];
		Scanner in=new Scanner(System.in);
		int n;
		n=in.nextInt();
		for(int i=1;i<=n;i++){
			a[i]=in.nextInt();
		}
		builtree(1,n,1);
		boolean check=true;
		while(check){
			System.out.println("1.ENTER SUM QUERY:");
			System.out.println("2.ENTER MIN QUERY:");
			System.out.println("3.ENTER MAX QUERY:");
			System.out.println("4.ENTER UPDATE QUERY:");
			int choice=in.nextInt();
			if(choice==1){
				System.out.println("ENTER SUM QUERY:");
				int l=in.nextInt();
				int r=in.nextInt();
				System.out.println(sumquery(1,n,l,r,1));
			}
			if(choice==2){
				System.out.println("ENTER MIN QUERY:");
				int l=in.nextInt();
				int r=in.nextInt();
				System.out.println(minquery(1,n,l,r,1));
			}
			if(choice==3){
				System.out.println("ENTER MAX QUERY:");
				int l=in.nextInt();
				int r=in.nextInt();
				System.out.println(maxquery(1,n,l,r,1));
			}
			if(choice==4){
				System.out.println("ENTER UPDATE(+4) QUERY:");
				int l=in.nextInt();
				int r=in.nextInt();
				update(1,n,l,r,1);
			}
			if(choice==5){
				check=false;
			}
		}
    }
}

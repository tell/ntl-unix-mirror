
#include <NTL/ZZX.h>
#include <NTL/ZZ_pX.h>
#include <NTL/lzz_pX.h>
#include <NTL/GF2X.h>

#include <NTL/version.h>

NTL_CLIENT


#define make_string_aux(x) #x
#define make_string(x) make_string_aux(x)

int SmallModulusTest(long p, long n)
{
   zz_pBak bak;

   bak.save();


   zz_p::init(p);

   zz_pX a, b, c, cc;

   random(a, n);
   random(b, n);
   PlainMul(c, a, b);
   FFTMul(cc, a, b);

   int res;
   res = (c != cc);

   bak.restore();

   return res;
}


int GF2X_test()
{
   GF2X a, b, c, c1;

   long n;

#ifdef NTL_GF2X_LIB
   for (n = 32; n <= (1L << 18); n = n << 1) {
      random(a, n);
      random(b, n);
      OldMul(c, a, b);
      mul(c1, a, b);
      if (c1 != c) return 1;
   }
#endif

   return 0;
}

void GF2X_time()
{
   long n = 1000000L;
   long iter;

   GF2X a, b, c;

   double t;
   long i;

   random(a, n);
   random(b, n);

   mul(c, a, b);

   iter = 0;
   do {
      iter = iter ? (2*iter) : 1;
      t = GetTime();
      for (i = 0; i < iter; i++)
         mul(c, a, b);
      t = GetTime() - t;
   } while (t < 0.5);

   cerr << "time to multiply polynomials over GF(2) \n   of degree < 1000000: "
        << (t/iter) << "s\n";

#ifdef NTL_GF2X_LIB
   OldMul(c, a, b);

   iter = 0;
   do {
      iter = iter ? (2*iter) : 1;
      t = GetTime();
      for (i = 0; i < iter; i++)
         OldMul(c, a, b);
      t = GetTime() - t;
   } while (t < 0.5);

   cerr << "   **** using old code: "  << (t/iter) << "s\n";
#endif

}


ZZX SSMul(const ZZX& a, const ZZX& b)
{
   ZZX res;
   SSMul(res, a, b);
   return res;
}


int main()
{
   SetSeed(ZZ(0));


   cerr << "This is NTL version " << NTL_VERSION << "\n"; 

   cerr << "Hardware charactersitics:\n";
   cerr << "NTL_BITS_PER_LONG = " << NTL_BITS_PER_LONG << "\n";
   cerr << "NTL_ZZ_NBITS = " << NTL_ZZ_NBITS << "\n";
   cerr << "NTL_SP_NBITS = " << NTL_SP_NBITS << "\n";
   cerr << "\n";

   cerr << "Basic Configuration Options:\n";



#ifdef NTL_LEGACY_NO_NAMESPACE
   cerr << "NTL_LEGACY_NO_NAMESPACE\n";
#endif


#ifdef NTL_LEGACY_INPUT_ERROR
   cerr << "NTL_LEGACY_INPUT_ERROR\n";
#endif


#ifdef NTL_THREADS
   cerr << "NTL_THREADS\n";
#endif


#ifdef NTL_EXCEPTIONS
   cerr << "NTL_EXCEPTIONS\n";
#endif


#ifdef NTL_LEGACY_SP_MULMOD
   cout << "NTL_LEGACY_SP_MULMOD\n";
#endif


#ifdef NTL_DISABLE_LONGDOUBLE
   cout << "NTL_DISABLE_LONGDOUBLE\n";
#endif




#ifdef NTL_GMP_LIP
   cerr << "NTL_GMP_LIP\n";
#endif


#ifdef NTL_GF2X_LIB
   cerr << "NTL_GF2X_LIB\n";
#endif


#ifdef NTL_PCLMUL
   cerr << "NTL_PCLMUL\n";
#endif


#ifdef NTL_LONG_LONG_TYPE
   cerr << "NTL_LONG_LONG_TYPE: ";
   cerr << make_string(NTL_LONG_LONG_TYPE) << "\n";
#endif

#ifdef NTL_UNSIGNED_LONG_LONG_TYPE
   cerr << "NTL_UNSIGNED_LONG_LONG_TYPE: ";
   cerr << make_string(NTL_UNSIGNED_LONG_LONG_TYPE) << "\n";
#endif


#ifdef NTL_X86_FIX
   cerr << "NTL_X86_FIX\n";
#endif

#ifdef NTL_NO_X86_FIX
   cerr << "NTL_NO_X86_FIX\n";
#endif

#ifdef NTL_NO_INIT_TRANS
   cerr << "NTL_NO_INIT_TRANS\n";
#endif

#ifdef NTL_CLEAN_INT
   cerr << "NTL_CLEAN_INT\n";
#endif

#ifdef NTL_CLEAN_PTR
   cerr << "NTL_CLEAN_PTR\n";
#endif

#ifdef NTL_RANGE_CHECK
   cerr << "NTL_RANGE_CHECK\n";
#endif


cerr << "\n";
cerr << "Resolution of double-word types:\n";
cerr << make_string(NTL_LL_TYPE) << "\n";
cerr << make_string(NTL_ULL_TYPE) << "\n";


cerr << "\n";
cerr << "Performance Options:\n";

#ifdef NTL_LONG_LONG
   cerr << "NTL_LONG_LONG\n";
#endif

#ifdef NTL_AVOID_FLOAT
   cerr << "NTL_AVOID_FLOAT\n";
#endif

#ifdef NTL_SPMM_UL
   cerr << "NTL_SPMM_UL\n";
#endif


#ifdef NTL_SPMM_ULL
   cerr << "NTL_SPMM_ULL\n";
#endif


#ifdef NTL_SPMM_ASM
   cerr << "NTL_SPMM_ASM\n";
#endif




#ifdef NTL_AVOID_BRANCHING
   cerr << "NTL_AVOID_BRANCHING\n";
#endif


#ifdef NTL_FFT_BIGTAB
   cout << "NTL_FFT_BIGTAB\n";
#endif

#ifdef NTL_FFT_LAZYMUL
   cout << "NTL_FFT_LAZYMUL\n";
#endif





#ifdef NTL_TBL_REM
   cerr << "NTL_TBL_REM\n";
#endif


#ifdef NTL_TBL_REM_LL
   cerr << "NTL_TBL_REM_LL\n";
#endif


#ifdef NTL_GF2X_ALTCODE
   cerr << "NTL_GF2X_ALTCODE\n";
#endif

#ifdef NTL_GF2X_ALTCODE1
   cerr << "NTL_GF2X_ALTCODE1\n";
#endif


#ifdef NTL_GF2X_NOINLINE
   cerr << "NTL_GF2X_NOINLINE\n";
#endif

   cerr << "\n\n";

   cerr << "running tests";

   long n, k, i;

   n = 250;
   k = 16000;

   ZZ p;


   for (i = 0; i < 15; i++) {
      // cerr << n << "/" << k; 
      cerr << ".";
      RandomLen(p, k);
      ZZ_p::init(p);  

      ZZ_pX a, b, c, c1;


      random(a, n);
      random(b, n);

      FFTMul(c, a, b);

      c1 = conv<ZZ_pX>( SSMul( conv<ZZX>(a), conv<ZZX>(b) ) );

      if (c1 != c) {
         cerr << "ZZ_pX mul failed!\n";
         return 1;
      }

      n = long(n * 1.35);
      k = long(k / 1.414);
   }


   // small prime tests...I've made some changes in v5.3
   // that should be checked on various platforms, so 
   // we might as well check them here.

   if (SmallModulusTest(17, 1000)) {
      cerr << "first SmallModulusTest failed!!\n";
      return 1;
   }

   if (SmallModulusTest((1L << (NTL_SP_NBITS))-1, 1000)) {
      cerr << "second SmallModulusTest failed!!\n";
      return 1;
   }

   // Test gf2x code....

   if (GF2X_test()) {
      cerr << "GF2X test failed!\n";
      return 1;
   }
   

   cerr << "OK\n";

   ZZ x1, x2, x3, x4;
   double t;

   RandomLen(x1, 1024);
   RandomBnd(x2, x1);
   RandomBnd(x3, x1);

   mul(x4, x2, x3);

   t = GetTime();
   for (i = 0; i < 100000; i++)
      mul(x4, x2, x3);
   t = GetTime()-t;

   cerr << "time for 1024-bit mul: " << t*10 << "us";
   cerr << "\n";

   rem(x2, x4, x1);

   t = GetTime();
   for (i = 0; i < 100000; i++)
      rem(x2, x4, x1);
   t = GetTime()-t;

   cerr << "time for 2048/1024-bit rem: " << t*10 << "us";
   cerr << "\n";
   

   GenPrime(p, 1024);
   RandomBnd(x1, p);
   if (IsZero(x1)) set(x1);

   InvMod(x2, x1, p);

   t = GetTime();
   for (i = 0; i < 1000; i++)
      InvMod(x2, x1, p);
   t = GetTime()-t;

   cerr << "time for 1024-bit modular inverse: " << t*1000 << "us";
   cerr << "\n";



   // test modulus switching
   
   n = 1024;
   k = 1024;
   RandomLen(p, k);

   ZZ_p::init(p);

   ZZ_pX j1, j2, j3;

   random(j1, n);
   random(j2, n);

   mul(j3, j1, j2);

   t = GetTime();
   for (i = 0; i < 100; i++) mul(j3, j1, j2);
   t = GetTime()-t;

   cerr << "time to multiply degree 1023 polynomials\n   modulo a 1024-bit number: ";
   cerr << (t/100) << "s";
   cerr << "\n";

   GF2X_time();

   return 0;
}

void count_by(unsigned x, unsigned n, unsigned result[n])
{
    for (unsigned i = 0U, k = x; i < n; i++, k += x)
    {
        result[i] = k;
    }
}

int main()
{
    return 0;
}

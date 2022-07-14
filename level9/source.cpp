#include <string.h>
#include <stdlib.h>

class N {
	private:
		int		value;
		char	annotation[112];

	public:
		N(int value) {
			this->value = value;
		}
		
		N &		operator+(N &ref) {
			return N(ref.value + this->value);
		}
		
		N &		operator-(N &ref) {
			return N(this->value - ref.value);
		}
		
		void	setAnnotation(char *annotation)
		{
			size_t	n = strlen(annotation);

			memcpy(this->annotation, annotation, n);
		}
};

int		main(int argc, char **argv)
{
	N	*first;
	N	*sec;

	if (argc < 2)
		_exit(1);

	first = new N(5);
	sec = new N(6);
	first->setAnnotation(argv[1]);
	return sec->(sec, first);
}

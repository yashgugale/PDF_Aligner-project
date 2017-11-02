Title: PDF Aligner project

Problem Statement:
1. Often we want to print a book for which we have an e-copy. However, printing a colored copy is expensive. So we can either print a black and white copy (which may still be expensive) or print the pages in such a way that they are split and we have 2 pdf pages on one print page and the next two pages to its back and so on. However, we are well accustomed to reading the pages front-back and not side-side. Hence, the pdf pages must be aligned in such a way that upon printing, the first and second page will be back to back (aligned left) and the third and fourth pages will be on the 2nd half of the page back to back (aligned right).
This means that we can cut the page from the center and then place the two pages (now half in size) on top of each other and do this for all the pages such that we have our original book in correct sequence and then we can bind the pages together.

Description:
How to solve this task?
Steps:
1. Get the input file from the user.
2. Use pdfinfo to obtain information about the pdf.
3. Save the output in a text and extract the number of pages in the pdf using 'grep'.
4. Now split the pdf info individual pages, such that we have one pdf file for one page.
5. Now, using the page number obtained, add black pages such that we get pages as a multiple of four (Left->front-back = 2 pages. Right->front-back = 2 pages. Thus, 4 pages in total) so that upon printing the pdf, we have well aligned pages.
6. Rename the pages as: (original_1->new_1, original_2->new_4), (original_3->new_2, original_4->new_3)
7. Now, rejoin the renamed and realigned pdf pages to get one pdf. This, is done using pdftk.
8. Delete the redundant text files.
Note: This, new obtained PDF file will look misaligned when opened for normal viewing. But on printing, you will get the desired sequence which can then be joined to get the original book.

Libraries used:
1. pdftk
2. ps2pdf

Files:
1. Input test file: 	sample_file.pdf
2. Output file:		output.pdf
3. Source: 		PDF_Aligner.c
4. Exe(Linux distro):	PDF_Aligner

Output: Refer to the sample pdf's for getting clarity of how the rearranged pdf's will look.

Feel free to use, share and contribute.
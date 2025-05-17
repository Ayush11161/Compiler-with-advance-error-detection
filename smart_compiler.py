import subprocess
import sys
from error_analyzer import ErrorAnalyzer

def get_code_context(filename, line_number, context_lines=2):
    """Get the code context around the error line"""
    try:
        with open(filename, 'r') as f:
            lines = f.readlines()
            start = max(0, line_number - context_lines - 1)
            end = min(len(lines), line_number + context_lines)
            return ''.join(lines[start:end])
    except:
        return ""

def main():
    if len(sys.argv) < 2:
        print("Usage: python smart_compiler.py <source_file>")
        sys.exit(1)

    source_file = sys.argv[1]
    analyzer = ErrorAnalyzer()

    # Run the C compiler
    try:
        result = subprocess.run(['./compiler', source_file], 
                              capture_output=True, 
                              text=True)
        
        # If there are errors, analyze them
        if result.returncode != 0:
            print("\n=== Compilation Errors ===")
            
            # Process each line of error output
            for line in result.stderr.split('\n'):
                if line.strip():
                    # Try to extract line number from error message
                    line_number = None
                    if "line" in line.lower():
                        try:
                            line_number = int(line.split("line")[1].split(":")[0].strip())
                        except:
                            pass
                    
                    # Get code context if we have a line number
                    context = ""
                    if line_number:
                        context = get_code_context(source_file, line_number)
                    
                    # Analyze the error
                    analysis = analyzer.analyze_error(line, line_number, context)
                    
                    # Print the enhanced error message
                    print(f"\nError at line {analysis['line_number']}:")
                    print(f"Message: {analysis['message']}")
                    print(f"Explanation: {analysis['explanation']}")
                    print(f"Suggestion: {analysis['suggestion']}")
                    if context:
                        print(f"Code context:\n{context}")
                    print("-" * 50)
        else:
            print("Compilation successful!")
            
    except Exception as e:
        print(f"Error running compiler: {str(e)}")
        sys.exit(1)

if __name__ == "__main__":
    main() 
from flask import Flask, request, render_template

app = Flask(__name__)


@app.route('/')
def index():
    return render_template('index.html')


@app.route('/calculator')
def calculator():
    return render_template('calculator.html')


@app.route('/text')
def text():
    return render_template('text.html')


@app.route('/calculate', methods=['POST'])
def calculate():
    num1 = float(request.form['num1'])
    num2 = float(request.form['num2'])
    operator = request.form['operator']
    result = 0

    if operator == '+':
        result = num1 + num2
    elif operator == '-':
        result = num1 - num2
    elif operator == '*':
        result = num1 * num2
    elif operator == '/':
        if num2 == 0:
            error = "Nie można dzielić przez 0."
            return render_template('calculator.html', error=error)
        result = num1 / num2

    return render_template('calculator.html', result=result)


if __name__ == '__main__':
    app.run(debug=True)

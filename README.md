# ModelForge 
# Model selection: Pre-deep learning approach

Your intelligent companion for streamlined machine learning model selection and optimization


1. Introduction to the Script
2. Preparing Your Data
3. Model Warmup for Classification and Regression
4. Visualizing Model Performance
5. Conclusion

---

### 1. Introduction to the Script

This script is designed to assist users in the preliminary steps of machine learning model selection and evaluation. It provides functions for model warmup, which involves training and tuning several machine learning models using grid search cross-validation. The script supports both classification and regression tasks. 
Many times, before stepping into deep learning, we process our data and still don't know what model to use. Whether our problem is a regression one or a classification one, we have a variety of models to choose from such as SVC, SVR, Decision Trees, and more.

--- 

### What models does this script support

- DecisionTreeClassifier (see sklearn documentation of DTC) [link](https://scikit-learn.org/stable/modules/generated/sklearn.tree.DecisionTreeClassifier.html)
- DecisionTreeRegressor (see sklearn documentation of DTR) [link](https://scikit-learn.org/stable/modules/generated/sklearn.tree.DecisionTreeRegressor.html)
- GradientBoostingClassifier (see sklearn documentation of GBC) [link](https://scikit-learn.org/stable/modules/generated/sklearn.ensemble.GradientBoostingClassifier.html)
- GradientBoostRegressor (see sklearn documentation of GBR) [link](https://scikit-learn.org/stable/modules/generated/sklearn.ensemble.GradientBoostingRegressor.html)
- RandomForestClassifier (see sklearn documentation of RFC) [link](https://scikit-learn.org/stable/modules/generated/sklearn.ensemble.RandomForestClassifier.html)
- RandomForestRegressor (see sklearn documentation of RFR) [link](https://scikit-learn.org/stable/modules/generated/sklearn.ensemble.RandomForestRegressor.html)
- SVC (see sklearn documentation of SVC) [link](https://scikit-learn.org/stable/modules/generated/sklearn.svm.SVC.html)
- SVR (see sklearn documentation of SVR) [link](https://scikit-learn.org/stable/modules/generated/sklearn.svm.SVR.html)
- LogisticRegression (see sklearn documentation of LogisticRegression) [link](https://scikit-learn.org/stable/modules/generated/sklearn.linear_model.LogisticRegression.html)
- LinearRegression (see documentation of LinearRegression) [link](https://scikit-learn.org/stable/modules/generated/sklearn.linear_model.LinearRegression.html)
- Ridge (see sklearn documentation of Ridge) [link](https://scikit-learn.org/stable/modules/generated/sklearn.linear_model.Ridge.html)

--- 

### 2. Preparing Your Data

Before using the script, ensure that your data is properly preprocessed and split into training and validation sets. The `X_train`, `y_train`, `X_val`, and `y_val` variables should contain the features and target variables for training and validation.

--- 

### 3. Model Warmup for Classification and Regression

#### Classification:
To warm up classification models, call the `warmup_classification()` function with your training data. This function performs grid search cross-validation to find the best hyperparameters for logistic regression, decision tree, gradient boosting, random forest, and support vector machine (SVM) classifiers.

#### Regression:
To warm up regression models, call the `warmup_regression()` function with your training data. Similar to classification, this function performs grid search cross-validation to find the best hyperparameters for linear regression, decision tree, gradient boosting, random forest, and support vector regression (SVR) models.

---

### 4. Visualizing Model Performance

After warming up the models, you can visualize their performance on both the training and validation sets. The `visualization_class()` function is used for classification models, while the `visualization_regress()` function is used for regression models. These functions display the accuracy or R-squared scores of each model on the training and validation sets.

--- 

### 5. Conclusion

Using this script, you can efficiently explore various machine learning models, tune their hyperparameters, and evaluate their performance on your dataset. Experiment with different models and hyperparameters to find the best model for your specific task.

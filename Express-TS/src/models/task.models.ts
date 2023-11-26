import mongoose, { Schema, Document } from 'mongoose'
import { saveTasks } from '../types/types'
import { Importance, State } from '../types/types'

export interface TaskDocument extends saveTasks, Document {}

const tasksSchema = new Schema<TaskDocument>(
  {
    proyect: {
      type: String,
      required: true
    },
    createdBy: {
      type: String,
      required: true
    },
    user: {
      type: mongoose.Schema.Types.ObjectId,
      ref: 'User',
      required: true
    },
    title: {
      type: String,
      required: true
    },
    description: {
      type: String
    },
    assignedTo: {
      type: String,
      required: true
    },
    deadline: {
      type: Date,
      required: true
    },
    importance: {
      type: String,
      enum: Object.values(Importance),
      required: true
    },
    state: {
      type: String,
      enum: Object.values(State),
      required: true
    }
  },
  {
    timestamps: true
  }
)

// Define el modelo de mongoose
const TasksModel = mongoose.model<TaskDocument>('Tasks', tasksSchema)

export default TasksModel
